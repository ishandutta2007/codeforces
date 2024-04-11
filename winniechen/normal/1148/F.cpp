#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
ll sum,S,b[N],ans;int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%lld",&a[i],&b[i]),sum+=a[i];
	if(sum<0)for(int i=1;i<=n;i++)a[i]=-a[i];
	for(int i=0;i<62;i++)
	{
		S=0;
		for(int j=1;j<=n;j++)if(b[j]==1ll<<i)S+=a[j];
		if(S>0)
		{
			ans|=1ll<<i;
			for(int j=1;j<=n;j++)if(b[j]>>i&1)b[j]^=(1ll<<i),a[j]=-a[j];
		}for(int j=1;j<=n;j++)if(b[j]>>i&1)b[j]^=(1ll<<i);
	}
	printf("%lld\n",ans);
}