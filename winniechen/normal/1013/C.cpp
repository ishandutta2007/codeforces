#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 200005
int n,x;long long ans,a[N];
int main()
{
	scanf("%d",&n);if(n==1){puts("0");return 0;}
	for(int i=1;i<=(n<<1);i++)scanf("%lld",&a[i]);sort(a+1,a+(n<<1)+1);
	int h=1,t=n;
	for(int i=1;i<=n;i++)
	{
		if(h==1)ans=(a[t]-a[h])*(a[n<<1]-a[t+1]);
		else if(t!=(n<<1))ans=min(ans,(a[t]-a[h])*(a[n<<1]-a[1]));
		h++,t++;
	}
	printf("%lld\n",ans);
}