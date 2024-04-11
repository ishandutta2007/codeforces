#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 25
#define M 1<<20
double p[N],f[M],sum[M],ans[N];
int n,k,tmp,num[M];
double get(double x)
{
	//double ret=1,now=x;
	//while(now>1e-6)ret+=now,now*=x;
	//return ret;
	return 1.0/(1.0-x);
}
int main()
{
	// freopen("array.in","r",stdin);
	// freopen("array.out","w",stdout);
	scanf("%d%d",&n,&k);f[0]=1.0;
	for(int i=1;i<=n;i++){scanf("%lf",&p[i]),sum[1<<(i-1)]=p[i];if(p[i]<1e-8)tmp++;}
	k=min(n-tmp,k);
	for(int S=1;S<(1<<n);S++)
	{
		num[S]=num[S>>1]+(S&1);if(num[S]>k)continue;
		sum[S]=sum[S-(S&-S)]+sum[S&-S];
		for(int i=1;i<=n;i++)if((1<<(i-1))&S)
		{
			int s=S^(1<<(i-1));
			f[S]+=f[s]*get(sum[s])*p[i];
		}
		if(num[S]==k)
			for(int i=1;i<=n;i++)if((1<<(i-1))&S)ans[i]+=f[S];
	}
	for(int i=1;i<=n;i++)printf("%.6lf ",ans[i]);puts("");

    return 0;
}