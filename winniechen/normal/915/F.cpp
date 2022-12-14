#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1000005
#define ll long long
struct node{int to,next;}e[N<<1];
int fa[N],siz[N],n,idx[N],head[N],cnt,a[N];ll ans;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool cmp(const int &x,const int &y){return a[x]<a[y];}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),idx[i]=i,fa[i]=i,siz[i]=1;sort(idx+1,idx+n+1,cmp);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int j=1;j<=n;j++)
	{
		int x=idx[j];
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(a[to1]>a[x])continue;
			if(find(x)!=find(to1))
			{
				ans+=(ll)siz[find(x)]*siz[find(to1)]*a[x];
				siz[find(x)]+=siz[find(to1)];fa[find(to1)]=find(x);
			}
		}
	}
	for(int i=1;i<=n;i++)siz[i]=1,fa[i]=i;
	for(int j=n;j;j--)
	{
		int x=idx[j];
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(a[to1]<a[x])continue;
			if(find(x)!=find(to1))
			{
				ans-=(ll)siz[find(x)]*siz[find(to1)]*a[x];
				siz[find(x)]+=siz[find(to1)];fa[find(to1)]=find(x);
			}
		}
	}
	printf("%lld\n",ans);
}