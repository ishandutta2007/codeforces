#include<stdio.h>
#include<algorithm>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
double f[3010][310],p[3010][310],c[3010],q[3010],z;
int n,m,x;
int main()
{
	scanf("%d%d",&n,&m);
	fr(i,m)
		f[0][i]=1;
	fr(i,n)
		fr(j,m)
		{
			scanf("%d",&x),p[i][j]=x/1000.;
			f[i+1][j]=f[i][j]*(1-p[i][j]);
		}
	fr(i,m)
		q[i]=1-f[n][i];
	fr(i,n)
	{
		int k=max_element(q,q+m)-q;
		z+=q[k];
		fr(j,n)
			c[j+1]=c[j]*(1-p[j][k])+f[j][k]*p[j][k];
		fr(j,n)
			f[j][k]=c[j];
		q[k]-=c[n];
	}
	printf("%.10f\n",z);
}