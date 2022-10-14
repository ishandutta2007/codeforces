#include <bits/stdc++.h>
#define SZ 100005
#define BT 128*1024*2
using namespace std;

int n,m,q,a[15][SZ];
struct node
{
	int cnt,lc[15],rc[15],lv[15],rv[15],cid;
	void init(int id)
	{
		for(int i=1;i<=n;i++) lv[i]=rv[i]=a[i][id];
		cid=0;cnt=0;
		for(int i=1;i<=n;i++)
		{
			int ptr=i;
			while(ptr+1<=n&&a[i][id]==a[ptr+1][id]) ptr++;
			for(int j=i;j<=ptr;j++) lc[j]=cid,rc[j]=cid;
			cid++;cnt++;i=ptr;
		}
	}
};
node st[BT];
node merge(node ln,node rn)
{
	node ret;
	ret.cnt=ln.cnt+rn.cnt;
	for(int i=1;i<=n;i++)
	{
		ret.lv[i]=ln.lv[i];
		ret.rv[i]=rn.rv[i];
		rn.lc[i]+=ln.cid;
		rn.rc[i]+=ln.cid;
	}
	for(int i=1;i<=n;i++) if(ln.rv[i]==rn.lv[i]&&ln.rc[i]!=rn.lc[i])
	{
		ret.cnt--;
		int cc=rn.lc[i];
		for(int j=1;j<=n;j++) if(ln.lc[j]==cc) ln.lc[j]=ln.rc[i];
		for(int j=1;j<=n;j++) if(ln.rc[j]==cc) ln.rc[j]=ln.rc[i];
		for(int j=1;j<=n;j++) if(rn.lc[j]==cc) rn.lc[j]=ln.rc[i];
		for(int j=1;j<=n;j++) if(rn.rc[j]==cc) rn.rc[j]=ln.rc[i];
	}
	for(int i=1;i<=n;i++)
	{
		ret.lc[i]=ln.lc[i];
		ret.rc[i]=rn.rc[i];
	}
	vector<int> vec(ln.cid+rn.cid+1,-1);
	ret.cid=0;
	for(int i=1;i<=n;i++)
	{
		if(vec[ret.lc[i]]==-1) vec[ret.lc[i]]=ret.cid++;
		ret.lc[i]=vec[ret.lc[i]];
	}
	for(int i=1;i<=n;i++)
	{
		if(vec[ret.rc[i]]==-1) vec[ret.rc[i]]=ret.cid++;
		ret.rc[i]=vec[ret.rc[i]];
	}
	return ret;
}
void build(int l,int r,int v)
{
	if(l==r)
	{
		st[v].init(l);
		return;
	}
	int m=(l+r)/2;
	build(l,m,v*2+1);
	build(m+1,r,v*2+2);
	st[v]=merge(st[v*2+1],st[v*2+2]);
}
node query(int l,int r,int v,int ql,int qr)
{
	if(ql<=l&&r<=qr) return st[v];
	int m=(l+r)/2;
	if(qr<=m) return query(l,m,v*2+1,ql,qr);
	if(ql>m) return query(m+1,r,v*2+2,ql,qr);
	return merge(query(l,m,v*2+1,ql,qr),query(m+1,r,v*2+2,ql,qr));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	build(1,m,0);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		node res=query(1,m,0,l,r);
		printf("%d\n",res.cnt);
	}
	return 0;
}