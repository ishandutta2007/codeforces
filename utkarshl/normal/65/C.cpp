#include"stdio.h"
#include"algorithm"
#include"cmath"
#define s(x) scanf("%d",&x)
using namespace std;
inline double sqr(double a){return a*a;}
int x[10001],y[10001],z[10001],vp,vs,px,py,pz,n;
double d[10001];
bool test(int i)
{
	return d[i]/vs+1e-9>sqrt(sqr(x[i]-px)+sqr(y[i]-py)+sqr(z[i]-pz))/vp;
}
int main()
{
	s(n);
	d[0]=0;
	for(int i=0;i<=n;i++)
	{
		s(x[i]),s(y[i]),s(z[i]);
		if(i)d[i]=d[i-1]+sqrt(sqr(x[i]-x[i-1])+sqr(y[i]-y[i-1])+sqr(z[i]-z[i-1]));
	}
	s(vp),s(vs),s(px),s(py),s(pz);
	if(!test(n)){printf("NO");return 0;}
	int upper=n,lower=0;
	while(upper!=lower+1)
	{
		int mid=(upper+lower)>>1;
		if(test(mid))upper=mid;else lower=mid;
	}
	double timeL=d[lower]/vs,timeU=d[lower+1]/vs,time=timeL,delta=timeU-timeL;
	while(timeL*vs+1e-10<timeU*vs)
	{
		double 	mid=(timeL+timeU)/2,
			xm=x[lower]+(x[lower+1]-x[lower])*(mid-time)/delta,
			ym=y[lower]+(y[lower+1]-y[lower])*(mid-time)/delta,
			zm=z[lower]+(z[lower+1]-z[lower])*(mid-time)/delta;
		if(mid<sqrt(sqr(xm-px)+sqr(ym-py)+sqr(zm-pz))/vp)timeL=mid;
		else timeU=mid;
//		printf("%.10f %.10f %.10f %.10f\n",xm,ym,zm,timeU-timeL);
	}
	double 	mid=(timeL+timeU)/2,
	xm=x[lower]+(x[lower+1]-x[lower])*(mid-time)/delta,
	ym=y[lower]+(y[lower+1]-y[lower])*(mid-time)/delta,
	zm=z[lower]+(z[lower+1]-z[lower])*(mid-time)/delta;
//	printf("%d %f %f %f\n",vp,xm-px,ym-py,zm-pz);
	printf("YES\n%.10f\n%.10f %.10f %.10f\n",mid,xm,ym,zm);
}