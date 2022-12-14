#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N 105
#define ll long long
ll a[N],ans,sum;
int main()
{
	for(int i=1;i<=14;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=14;i++)
	{
		ans=0;
		if(a[i])
		{
			ll x=a[i]%14;
			ll y=a[i]/14;
			if(!(y&1))ans+=y;
			for(int j=1;j<=13;j++)
			{
				if(j<=x)
				{
					if(!((a[(i+j-1)%14+1]+y+1)&1))ans+=(a[(i+j-1)%14+1]+y+1);
				}else
				{
					if(!((a[(i+j-1)%14+1]+y)&1))ans+=(a[(i+j-1)%14+1]+y);
				}
			}
		}
		sum=max(ans,sum);
	}
	printf("%I64d\n",sum);
	return 0;
}