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
ll A,B,C,x[2],y[2];
double res,a[4],b[4];
int main()
{
	scanf("%lld%lld%lld",&A,&B,&C);
	scanf("%lld%lld%lld%lld",&x[0],&y[0],&x[1],&y[1]);
	res=abs(x[0]-x[1])+abs(y[0]-y[1]);
	b[0]=-A*x[0]-C,a[0]=x[0]*A;
	b[1]=y[0]*B,a[1]=-B*y[0]-C;
	b[2]=-A*x[1]-C,a[2]=x[1]*A;
	b[3]=y[1]*B,a[3]=-B*y[1]-C;
	for(int i=0;i<2;i++)
		for(int j=2;j<4;j++)
		{
			double dis1=fabs(b[j]-b[i])/B;
			double dis2=fabs(a[j]-a[i])/A;
			res=min(res,sqrt(dis1*dis1+dis2*dis2)+fabs(x[0]-a[i]/A)+fabs(y[0]-b[i]/B)+fabs(x[1]-a[j]/A)+fabs(y[1]-b[j]/B));
		}
	double ans=res;
	printf("%.10lf",ans);
}