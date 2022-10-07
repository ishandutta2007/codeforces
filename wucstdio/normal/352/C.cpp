#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,x;
double sum,ans=2147483647;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		double xx;
		scanf("%lf",&xx);
		sum+=xx-floor(xx);
		if(xx-floor(xx)<1e-9)x++;
	}
	for(int i=max(0,x-n);i<=min(n,x);i++)
	  ans=min(ans,abs(sum-n+i));
	printf("%.3lf\n",ans);
	return 0;
}