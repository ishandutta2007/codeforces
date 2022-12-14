#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 200005
#define ll long long
#define ls rt<<1
#define rs rt<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll sum[N<<2],ans,last;
int minx[N<<2],minn[N<<2],cn[N<<2],n;
vector<int> v[N];
void PushUp(int rt)
{
	sum[rt]=sum[ls]+sum[rs];
	if(minn[ls]<minn[rs])minn[rt]=minn[ls],cn[rt]=cn[ls],minx[rt]=min(minn[rs],minx[ls]);
	else if(minn[ls]==minn[rs])minn[rt]=minn[ls],cn[rt]=cn[ls]+cn[rs],minx[rt]=min(minx[rs],minx[ls]);
	else minn[rt]=minn[rs],cn[rt]=cn[rs],minx[rt]=min(minn[ls],minx[rs]);
}
void PushDown(int rt)
{
	if(minn[ls]<minn[rt])
	{
		sum[ls]+=1ll*(minn[rt]-minn[ls])*cn[ls],minn[ls]=minn[rt];
	}
	if(minn[rs]<minn[rt])
	{
		sum[rs]+=1ll*(minn[rt]-minn[rs])*cn[rs],minn[rs]=minn[rt];
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		minn[rt]=sum[rt]=l;cn[rt]=1;minx[rt]=1<<30;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);build(rson);
	PushUp(rt);
}
void Update(int L,int R,int c,int l,int r,int rt)
{
	//printf("%d %d %d %d %d %d\n",l,r,L,R,c,minn[rt]);
	if(minn[rt]>=c)return ;
	if(L<=l&&r<=R&&minx[rt]>c)
	{
		sum[rt]+=1ll*(c-minn[rt])*cn[rt],minn[rt]=c;
		return ;
	}
	PushDown(rt);int m=(l+r)>>1;
	if(L<=m)Update(L,R,c,lson);if(R>m)Update(L,R,c,rson);PushUp(rt);
}
void get(int x,int y)
{
	for(int i=1;i*i<=x;i++)
	{
		if(!(x%i))
		{
			v[i].push_back(y);
			if(i*i==x)continue;
			v[x/i].push_back(y);
		}
	}
}
int query(int x,int l,int r,int rt)
{
	if(l==r)return minn[rt];
	PushDown(rt);int m=(l+r)>>1;
	if(x<=m)return query(x,lson);return query(x,rson);
}
int main()
{
	scanf("%d",&n);
	int o=0;
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		get(x,i);o=max(o,x);
	}
	build(1,n,1);last=1ll*n*(n+1)-sum[1];
	for(int i=o;i>=1;i--)
	{
		int x=v[i].size();
		//if(i==1)printf("%d\n",last);
		if(x>=2)
		{
			//printf("%d %d\n",v[i][x-2],v[i][x-1]);
			Update(1,v[i][0],v[i][x-2],1,n,1);
			Update(v[i][0]+1,v[i][1],v[i][x-1],1,n,1);
			if(v[i][1]!=n)Update(v[i][1]+1,n,n+1,1,n,1);
			//printf("%d\n",sum[1]);
			ll t=1ll*n*(n+1)-sum[1];
			ans+=1ll*(last-t)*i;
			last=t;
		//printf("%lld\n",ans);
		}
		//if(i==1)
		//{
			// int ret=0;
			// for(int j=1;j<=n;j++)ret=ret+query(j,1,n,1);
			// printf("%d\n",ret);
		// }
	}
	printf("%lld\n",ans);
	return 0;
}