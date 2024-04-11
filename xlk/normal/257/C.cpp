#include <stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
double k[100020];
double x[100020];
double y[100020];
double pi=acos(-1.);
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",x+i,y+i);
	x[n]=x[0],y[n]=y[0];
	for(int i=0;i<n;i++)
	{
		k[i]=atan2(y[i],x[i]);
	}
	sort(k,k+n);
	double z=0;
	for(int i=1;i<n;i++)
		z=max(z,k[i]-k[i-1]);
	z=max(z,k[0]-k[n-1]+2*pi);
	z=z/pi*180;
	printf("%.9f",360-z);
	return 0;
}