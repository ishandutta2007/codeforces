#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 1000000007
struct node{int x,y;}a[N];
int fa[N<<1],num[N<<1],siz[N<<1],p[N],n,ans,q[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int main()
{
	scanf("%d",&n);ans=1;
	for(int i=1;i<=n<<1;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		p[i]=a[i].x,q[i]=a[i].y;
	}sort(p+1,p+n+1),sort(q+1,q+n+1);
	for(int i=1;i<=n;i++)a[i].x=lower_bound(p+1,p+n+1,a[i].x)-p,a[i].y=lower_bound(q+1,q+n+1,a[i].y)-q+n;
	for(int i=1;i<=n;i++)
	{
		int x=find(a[i].x),y=find(a[i].y);
		if(x!=y)
		{
			fa[x]=y;siz[y]+=siz[x];
			num[y]+=num[x]+1;
		}else num[x]++;
	}
	for(int i=1;i<=(n<<1);i++)
	{
		if(fa[i]==i)
		{
			if(siz[i]<=num[i])ans=(ll)ans*q_pow(2,siz[i])%mod;
			else ans=(ll)ans*(q_pow(2,siz[i])-1)%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
}