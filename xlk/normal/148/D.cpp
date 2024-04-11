#include<stdio.h>
double f[1020][1020];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			double w=i,b=j;
			f[i][j]=w/(w+b);
			if(j>1)
				f[i][j]+=b/(w+b)*(b-1)/(w+b-1)*w/(w+b-2)*f[i-1][j-2];
			if(j>2)
				f[i][j]+=b/(w+b)*(b-1)/(w+b-1)*(b-2)/(w+b-2)*f[i][j-3];
		}
	printf("%.9lf\n",f[n][m]);
	return 0;
}