#include<iostream>
#include<stdio.h>
using namespace std;
int n,p,a[60],b[60],d[60],c,x;
double f[120][120][120],z;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>p;
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=p;k++)
			{
				f[i+1][j][k]+=f[i][j][k];
				f[i+1][j+1][k+a[i]]+=f[i][j][k];
			}
	for(int j=0;j<=n;j++)
	{
		double c=1;
		for(int i=0;i<j;i++)
			c=c*(i+1);
		for(int i=0;i<n-j;i++)
			c=c*(i+1);
		for(int k=0;k<=p;k++)
			z+=f[n][j][k]*c;
	}
	for(int i=0;i<n;i++)
		z/=i+1;
	printf("%.10f",z-1);
	return 0;
}