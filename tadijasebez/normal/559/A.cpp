#include <stdio.h>
#include <cmath>
/*double sol;
double TriangleArea(int a, int b, int c)
{
	double s=(double)(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
double TriangleArea(int a, int b, double c)
{
	double s=(double)(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
double CalcSide(int a, int b)
{
	double aa=(double) a;
	double bb=(double) b;
	double c=3/4*aa*aa+(bb+aa/2)*(bb+aa/2);
	return sqrt(c);
}*/
int main()
{
	int a[6],i;
	for(i=0;i<6;i++) scanf("%i",&a[i]);
	int ans=0;
	ans+=a[0]+a[1]+a[2];
	ans=ans*ans;
	ans-=a[0]*a[0]+a[2]*a[2]+a[4]*a[4];
	printf("%i\n",ans);
	/*sol=TriangleArea(a[0],a[1],CalcSide(a[0],a[1]));
	printf("%llf\n",sol);
	sol+=TriangleArea(a[2],a[3],CalcSide(a[2],a[3]));
	printf("%llf\n",sol);
	sol+=TriangleArea(a[4],a[5],CalcSide(a[4],a[5]));
	printf("%llf\n",sol);
	sol+=TriangleArea(CalcSide(a[0],a[1]),CalcSide(a[2],a[3]),CalcSide(a[4],a[5]));
	printf("%llf\n",sol);
	double t=TriangleArea(1,1,1);
	printf("%llf\n",sol/t);
	printf("%llf\n",TriangleArea(1,1,1));*/
	return 0;
}