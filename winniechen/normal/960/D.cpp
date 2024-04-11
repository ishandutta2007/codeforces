#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 64
long long mov[N];
int main()
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int op;
		long long x,y;
		scanf("%d%lld",&op,&x);
		if(op==1)
		{
			scanf("%lld",&y);
			int dep=0;
			while(x)
			{
				dep++;
				x=x>>1;
			}
			mov[dep]+=y;
			mov[dep]%=(1ll<<(dep-1));
			(mov[dep]+=(1ll<<(dep-1)))%=(1ll<<(dep-1));
			mov[dep+1]-=y*2;
			mov[dep+1]%=(1ll<<dep);
			(mov[dep+1]+=(1ll<<dep))%=(1ll<<dep);
		}else if(op==2)
		{
			scanf("%lld",&y);
			int dep=0;
			while(x)
			{
				dep++;
				x=x>>1;
			}
			mov[dep]+=y;
			mov[dep]%=(1ll<<(dep-1));
			(mov[dep]+=(1ll<<(dep-1)))%=(1ll<<(dep-1));
		}else if(op==3)
		{
			long long t=x;int dep=0;
			while(t)
			{
				dep++;
				t=t>>1;
			}
			while(x)
			{
				printf("%I64d ",x);
				x=(x+mov[dep]+(1ll<<(dep-1)))%(1ll<<(dep-1))+(1ll<<(dep-1));
				dep--,x=x>>1;
			}
			puts("");
		}
	}
	return 0;
}