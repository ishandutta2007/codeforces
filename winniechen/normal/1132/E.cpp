#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 10
#define ll long long
ll w,a[N],ans,b[N];
int f[10005];
int main()
{
	scanf("%lld",&w);
	for(int i=1;i<=8;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=7;i++)b[i]=min(a[i],100ll),a[i]-=b[i];
	ll now=0;
	f[0]=1;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=b[i];j++)
			for(int k=10000;k>=i;k--)
				f[k]|=f[k-i];
	for(int i=8;i;i--)
	{
		ll tmp=min((w-now)/i,a[i]);
		now+=tmp*i;
		if(w-now<=10000)
		{
			for(ll t=now;tmp&&w-t<=10000;tmp--,t-=i)
				for(int j=0;j<=w-t;j++)if(f[j])
				{
					if(j-now+t<=10000&&j-now+t>0)f[j-now+t]=1;
					ans=max(ans,t+j);
				}
		}
	}
	for(int j=10000;~j;j--)if(f[j]&&now+j<=w)ans=max(ans,now+j);
	printf("%lld\n",ans);
}

// 1223123123