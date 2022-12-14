#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
int n,m;
long long k;
int main()
{
	scanf("%d%d%I64d",&n,&m,&k);
	if(k<n)
	{
		printf("%I64d %d\n",k+1,1);
		return 0;
	}else
	{
		if(k>=1ll*n*m-1ll)
		{
			printf("%d %d\n",1,2);
			return 0;
		}
		k=k-n+1;
		int y=(k-1)/(m-1);
		int x=(k-1)%(m-1)+1;
		if(y&1)
		{
			printf("%d %d\n",n-y,m-x+1);
		}else
		{
			printf("%d %d\n",n-y,x+1);
		}
	}
	return 0;
}