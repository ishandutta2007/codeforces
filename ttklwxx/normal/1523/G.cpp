#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct tree
{
	int l,r,rt;
}t[800004];
int ch[20000005][2],minn[20000005],cnt;
int n;
void build(int l,int r,int k)
{
	t[k].l=l;
	t[k].r=r;
	t[k].rt=0;
	if(l==r)return;
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void insert(int &k,int l,int r,int x,int y)
{
	if(k==0)k=++cnt,minn[k]=1000000000;
	if(l==r)
	{
		minn[k]=min(minn[k],y);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)insert(ch[k][0],l,mid,x,y);
	else insert(ch[k][1],mid+1,r,x,y);
	minn[k]=min(minn[ch[k][0]],minn[ch[k][1]]);
}
void change(int wz,int k,int tl,int x)
{
	if(t[k].l>wz||t[k].r<wz)return;
	insert(t[k].rt,1,n,tl,x);
	if(t[k].l==t[k].r)return;
	if(wz<=t[k<<1].r)change(wz,k<<1,tl,x);
	else change(wz,k<<1|1,tl,x);
}
int findmin(int k,int l,int r,int ql,int qr)
{
	if(k==0)return 1000000000;
	if(l>qr||r<ql)return 1000000000;
	if(l>=ql&&r<=qr)return minn[k];
	return min(findmin(ch[k][0],l,(l+r)>>1,ql,qr),findmin(ch[k][1],((l+r)>>1)+1,r,ql,qr));
}
int query(int l,int r,int k)
{
	if(t[k].l>r)return 1000000000;
	if(t[k].r<=r)return findmin(t[k].rt,1,n,l,n);
	return min(query(l,r,k<<1),query(l,r,k<<1|1));
}
int tl[100005],tr[100005],pos[100005];
bool bi(int x,int y)
{
	return tr[x]-tl[x]>tr[y]-tl[y];
}
int ans;
void findans(int l,int r)
{
	if(l>r)return;
	//printf("vis:%d %d\n",l,r);
	int sth=query(l,r,1);
	//printf("orz%d\n",sth);
	if(sth==1000000000)return;
	ans+=tr[sth]-tl[sth]+1;
	findans(l,tl[sth]-1);
	findans(tr[sth]+1,r);
}
int tans[200005];
int main()
{
	int m;
	n=read();
	m=read();
	minn[0]=1000000000;
	for(int i=1;i<=m;i++)
	{
		tl[i]=read();
		tr[i]=read();
		pos[i]=i;
	}
	sort(pos+1,pos+m+1,bi);
	int x=1;
	build(1,n,1); 
	//printf("orz\n"); 
	for(int i=n;i>=1;i--)
	{
		while(x<=m&&tr[pos[x]]-tl[pos[x]]+1==i)change(tr[pos[x]],1,tl[pos[x]],pos[x]),x++;
		//printf("1\n");
		ans=0;
		findans(1,n);
		tans[i]=ans;
	}
	for(int i=1;i<=n;i++)printf("%d\n",tans[i]);
	return 0;
}