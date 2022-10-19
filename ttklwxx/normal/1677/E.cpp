#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
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
int p[200005];
struct query
{
	int l,r,id;
}q[1000005];
int qans[1000005];
bool bi(struct query x,struct query y)
{
	return x.r<y.r;
}
struct tree
{
	int l,r,minn,sl,laz,ti,ans;
}a[800004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].laz=0;
	a[k].ti=0;
	a[k].ans=0;
	a[k].minn=1000000000;
	a[k].sl=r-l+1;
	if(l==r)
	{
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void pushdown(int k)
{
	if(a[k].laz!=0)
	{
		a[k<<1].minn+=a[k].laz;
		a[k<<1].laz+=a[k].laz;
		a[k<<1|1].minn+=a[k].laz;
		a[k<<1|1].laz+=a[k].laz;
		a[k].laz=0;
	}
	if(a[k].ti!=0)
	{
		if(a[k<<1].minn==a[k].minn)
		{
			a[k<<1].ans+=a[k<<1].sl*a[k].ti;
			a[k<<1].ti+=a[k].ti;
		}
		if(a[k<<1|1].minn==a[k].minn)
		{
			a[k<<1|1].ans+=a[k<<1|1].sl*a[k].ti;
			a[k<<1|1].ti+=a[k].ti;
		}
		a[k].ti=0;
	}
}
void change(int l,int r,int k,int x)
{
	if(a[k].l>r||a[k].r<l)return;
	if(a[k].l>=l&&a[k].r<=r)
	{
		a[k].minn+=x;
		a[k].laz+=x;
		return;
	}
	pushdown(k);
	change(l,r,k<<1,x);
	change(l,r,k<<1|1,x);
	a[k].minn=min(a[k<<1].minn,a[k<<1|1].minn);
	a[k].sl=0;
	if(a[k].minn==a[k<<1].minn)a[k].sl+=a[k<<1].sl;
	if(a[k].minn==a[k<<1|1].minn)a[k].sl+=a[k<<1|1].sl;
	a[k].ans=a[k<<1].ans+a[k<<1|1].ans;
}
int query(int l,int r,int k)
{
	if(l>a[k].r||r<a[k].l)return 0;
	if(a[k].l>=l&&a[k].r<=r)return a[k].ans;
	pushdown(k);
	return query(l,r,k<<1)+query(l,r,k<<1|1);
}
int sta[200005],ttop;
int dy[200005];
int maxl[200005],maxr[200005];
vector<int>vl[200005],vr[200005],gx[200005];
int maxq[1000005];
signed main()
{
	int n,xw;
	n=read();
	xw=read();
	for(int i=1;i<=n;i++)p[i]=read(),dy[p[i]]=i;
	for(int i=1;i<=n;i++)maxl[i]=1,maxr[i]=n;
	ttop=0;
	for(int i=1;i<=n;i++)
	{
		while(ttop>=1&&p[sta[ttop]]<p[i])
		{
			maxr[sta[ttop]]=i-1;
			ttop--;
		}
		sta[++ttop]=i;
	}
	ttop=0;
	for(int i=n;i>=1;i--)
	{
		while(ttop>=1&&p[sta[ttop]]<p[i])
		{
			maxl[sta[ttop]]=i+1;
			ttop--;
		}
		sta[++ttop]=i;
	}
	//for(int i=1;i<=n;i++)printf("%lld %lld\n",maxl[i],maxr[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i*(i+1);j<=n;j+=i)
		{
			int sth=j/i;
			if(dy[i]<maxl[dy[j]]||dy[i]>maxr[dy[j]])continue;
			if(dy[sth]<maxl[dy[j]]||dy[sth]>maxr[dy[j]])continue;
			int lmax=dy[j],rmax=dy[j];
			if(dy[i]<dy[j])lmax=min(lmax,dy[i]);
			else rmax=max(rmax,dy[i]);
			if(dy[sth]<dy[j])lmax=min(lmax,dy[sth]);
			else rmax=max(rmax,dy[sth]);
			vl[rmax].push_back(maxl[dy[j]]);
			vr[rmax].push_back(lmax);
			gx[rmax].push_back(1);
			vl[maxr[dy[j]]+1].push_back(maxl[dy[j]]);
			vr[maxr[dy[j]]+1].push_back(lmax);
			gx[maxr[dy[j]]+1].push_back(-1);
			//printf("orz%lld %lld %lld %lld\n",maxl[dy[j]],lmax,rmax,maxr[dy[j]]);
		}
	}
	for(int i=1;i<=xw;i++)
	{
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
		maxq[i]=(q[i].r-q[i].l+1)*(q[i].r-q[i].l+2)/2;
	}
	sort(q+1,q+xw+1,bi);
	build(1,n,1);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		change(i,i,1,-1000000000);
		for(int j=0;j<vl[i].size();j++)
		{
			change(vl[i][j],vr[i][j],1,gx[i][j]);
		}
		a[1].ti++;
		a[1].ans+=a[1].sl;
		while(now<=xw&&q[now].r==i)
		{
			qans[q[now].id]=query(q[now].l,q[now].r,1);
			now++;
		}
	}
	for(int i=1;i<=xw;i++)printf("%lld\n",maxq[i]-qans[i]);
	return 0;
}