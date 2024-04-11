#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
struct node{int to,next;}e[N<<1];
struct Poi
{
	ll val;int num,used;
	Poi(){val=-0x3f3f3f3f3f3f3f3fll;num=0;}
	Poi(ll x,int y,int z){val=x,num=y,used=z;}
	bool operator < (const Poi &a) const {return val==a.val?num<a.num:val<a.val;}
	bool operator > (const Poi &a) const {return val==a.val?num>a.num:val>a.val;}
}g[N];
int head[N],cnt,a[N],n;ll f[N],ans1=-0x3f3f3f3f3f3f3f3fll,ans2;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
	f[x]=a[x];//ll mx=0;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs(to1,x),f[x]+=max(f[to1],0ll);//,mx=max(f[to1],mx);
	}
	ans1=max(ans1,f[x]);
}
void dfs2(int x,int from)
{
	f[x]=a[x];
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs2(to1,x),f[x]+=max(f[to1],0ll);
	}
	if(f[x]==ans1)ans2++,f[x]=0;
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs(1,0);dfs2(1,0);
	printf("%lld %d\n",ans1*ans2,ans2);
}