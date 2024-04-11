#include <stdio.h>
const int N=10050;
double max(double a, double b){ return a>b?a:b;}
double DP[N],L[N],R[N],V[N],C;
int n,m,i,j;
int main()
{
	scanf("%i %i",&n,&m);
	C=m/1000000.00;
	for(i=0;i<=n;i++)
	{
		scanf("%i",&m);
		if(m==0) V[i]=1;
		else V[i]=(long long)m*1e20;
		DP[i]=i;
	}
	for(i=0;i<n;i++)
		L[i]=V[i+1]/V[i]*(i+1)/(n-i);
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			R[j]=(R[j]+R[j+1]*L[j]+L[j])/(1+L[j]);
			L[j]=L[j]*(1+L[j+1])/(1+L[j]);
			DP[j]=max((double)j,(DP[j+1]-DP[j])*(R[j]/(n-i))+DP[j]-C);
		}
	}
	printf("%.10Lf\n",DP[0]);
	return 0;
}