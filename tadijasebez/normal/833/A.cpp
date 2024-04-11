#include <stdio.h>
#include <math.h>
#include <cmath>
bool Check(long long x, long long y)
{
	double q=cbrt (x*y);
	long long qq=ceil(q);
	if(qq*qq*qq == x*y)
	{
		if(x%qq!=0 || y%qq!=0) return false;
		return true;
	}
	else return false;
}
int main()
{
	int n,i;
	int x,y;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		if(Check((long long) x, (long long) y)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}