#include <stdio.h>
#include <math.h>
double max(double a, double b)
{
	if(a>b) return a;
	else return b;
}
double x[2505],y[2505],dp1[2505][2505],dp2[2505][2505];
double dist(int i,int j){return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));}
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%lf %lf",&x[i],&y[i]);
	double res=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			k=(j+n-i)%n;
			dp1[j][k]=max(dp1[(j+n-1)%n][k]+dist((j+n-1)%n,j),dp2[k][(j+n-1)%n]+dist(j,k));
			res=max(res,dp1[j][k]);
		}
		for(j=0;j<n;j++)
		{
			k=(j+i)%n;
			dp2[j][k]=max(dp2[(j+1)%n][k]+dist((j+1)%n,j),dp1[k][(j+1)%n]+dist(j,k));
			res=max(res,dp2[j][k]);
		}
	}
	printf("%.10lf",res);
	return 0;
}