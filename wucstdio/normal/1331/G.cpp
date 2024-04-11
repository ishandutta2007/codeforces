#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[105];
int main()
{
	for(int i=1;i<=11;i++)scanf("%d",&a[i]);
	for(int i=11;i>=1;i--)
	{
		double res=a[i]*a[i]*a[i]*5+sqrt(abs(a[i]));
		printf("f(%d) = ",a[i]);
		if(res>=400)printf("MAGNA NIMIS!\n");
		else printf("%.2lf\n",res);
	}
	return 0;
}