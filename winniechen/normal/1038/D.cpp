#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 500005
#define ll long long
int a[N],n,q[N];ll sum[N],ans,f[N],maxx[N],mx[N],g[N];
void fix(int x,ll v){for(;x<N;x+=x&-x)maxx[x]=max(maxx[x],v);}
void update(int x,ll v){for(;x<N;x+=x&-x)mx[x]=max(mx[x],v);}
ll find(int x){ll ret=-0x3f3f3f3f3f3f3f3fll;for(;x;x-=x&-x)ret=max(mx[x],ret);return ret;}
ll query(int x){ll ret=-0x3f3f3f3f3f3f3f3fll;for(;x;x-=x&-x)ret=max(maxx[x],ret);return ret;}
int main()
{
	scanf("%d",&n);
	memset(mx,0xc0,sizeof(mx));memset(maxx,0xc0,sizeof(maxx));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum[i]=a[i]+sum[i-1],fix(i,sum[i]*2),update(i,-sum[i]*2);
	if(n==1){printf("%d\n",a[1]);return 0;}
	for(int i=1;i<=n;i++)
	{
		ll x=find(i-1);f[i]=sum[i]+x;fix(i,f[i]+sum[i]);//printf("%lld\n",x);
		x=query(i-1);g[i]=-sum[i]+x;update(i,g[i]-sum[i]);
		// printf("%lld %lld\n",f[i],g[i]);
	}printf("%lld\n",max(f[n],g[n]));
}