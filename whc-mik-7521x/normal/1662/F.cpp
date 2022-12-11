#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+10,INF=1e9,len=100;
int t,n,a,b,p[N];
int vec[N],cnt;
int d[N],q[N],he,ta;
#define ls p+1
#define rs p+((mid-l+1)<<1)
int Y(int x,int i){return i?x+p[x]:x-p[x];}
struct SegmentTree
{
	set<pii>s[N<<1];
	inline void upd(int p,int l,int r,int x,int y,int flg)
	{
		if(r-l<=len)return;
		if(flg)s[p].insert({y,x});
		else s[p].erase({y,x});
		int mid=(l+r)>>1;
		if(x<=mid)upd(ls,l,mid,x,y,flg);
		else upd(rs,mid+1,r,x,y,flg);
	} 
	inline void get(int p,int l,int r,int xl,int xr,int yl,int yr,int id)
	{
		if(xl>xr)return;
		if(xl<=l&&r<=xr)
		{
			if(r-l<=len)
			{
				for(int i=l;i<=r;i++)
					if(d[i]==-1&&Y(i,id)>=yl&&Y(i,id)<=yr)vec[++cnt]=i;
				return;
			}
			auto it=s[p].lower_bound({yl,0});
			for(;it!=s[p].end()&&it->fi<=yr;it++)vec[++cnt]=it->se;
			return;
		}
		int mid=(l+r)>>1;
		if(xl<=mid)get(ls,l,mid,xl,xr,yl,yr,id);
		if(xr>mid)get(rs,mid+1,r,xl,xr,yl,yr,id);
	}
	inline void clr(int p,int l,int r)
	{
		if(r-l<=len)return;
		s[p].clear();
		int mid=(l+r)>>1;
		clr(ls,l,mid),clr(rs,mid+1,r);
	}
}sgt[2];
inline void expand(int u)
{
	cnt=0;
	sgt[0].get(1,1,n,u+1,min(n,u+p[u]),-1e9,u,0);
	for(int i=1;i<=cnt;i++)
	{
		int v=vec[i];
		d[v]=d[u]+1,q[++ta]=v,sgt[0].upd(1,1,n,v,v-p[v],0),sgt[1].upd(1,1,n,v,v+p[v],0);
	}
	cnt=0;
	sgt[1].get(1,1,n,max(1,u-p[u]),u-1,u,1e9,1);
	for(int i=1;i<=cnt;i++)
	{
		int v=vec[i];
		d[v]=d[u]+1,q[++ta]=v,sgt[0].upd(1,1,n,v,v-p[v],0),sgt[1].upd(1,1,n,v,v+p[v],0);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]),sgt[0].upd(1,1,n,i,i-p[i],1),sgt[1].upd(1,1,n,i,i+p[i],1);
		for(int i=1;i<=n;i++)d[i]=-1;
		he=1,ta=0;
		q[++ta]=a,d[a]=0,sgt[0].upd(1,1,n,a,a-p[a],0),sgt[1].upd(1,1,n,a,a+p[a],0);
		while(he<=ta)
		{
			int u=q[he++];
			expand(u);
		}
		printf("%d\n",d[b]);
		sgt[0].clr(1,1,n),sgt[1].clr(1,1,n);
	}
	return 0;
}