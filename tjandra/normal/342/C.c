#include<stdio.h>
#include<math.h>
typedef unsigned u;
typedef double d;
int main()
{
	d R,h,r,K;
	u ans,k;
	scanf("%lf%lf",&R,&h);
	r=R/2;
	K=(h+r)/R;
	k=(u)K;
	ans+=k<<1;
	K=h+R-R*k+r;
	if(K>=r+r*sqrt(3))ans++;
	printf("%u\n",ans);
	return 0;
}