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
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		ll n,x,y,d;
		scanf("%lld%lld%lld%lld",&n,&x,&y,&d);
		if(abs(y-x)%d==0)printf("%d\n",abs(y-x)/d);
		else
		{
			ll ans1=1ll<<60,ans2=1ll<<60;
			if(y%d==1)ans1=(y-1)/d+ceil(1.0*x/d);
			if((n-y+1)%d==1)ans2=(n-y)/d+ceil(1.0*(n-x)/d);
			ans1=min(ans1,ans2);
			if(ans1>1e12)printf("-1\n");
			else printf("%d\n",ans1);
		}
	}
}