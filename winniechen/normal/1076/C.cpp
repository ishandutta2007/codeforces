#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		if(n==1){puts("N");continue;}
		long double l=0,r=n/2;
		for(int cas=1;cas<=200;cas++)
		{
			long double m=(l+r)/2;
			if(m*(n-m)>n)r=m;
			else l=m;
		}
		if(fabs((n-l)*l-n)>1e-8){puts("N");continue;}
		printf("Y %.12lf %.12lf\n",(double)(n-l),(double)l);
	}
}