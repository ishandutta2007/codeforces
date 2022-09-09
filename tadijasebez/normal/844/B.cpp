#include <stdio.h>
int Matrix[55][55];
long long pow(long long x, int k)
{
	long long ans=1;
	while(k)
	{
		if(k&1) ans*=x;
		x*=x;
		k>>=1;
	}
	return ans;
}
int main()
{
	int n,m,i,j,k,u;
	scanf("%i%i",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%i",&Matrix[i][j]);
		}
	}
	long long sol=0;
	for(i=0;i<n;i++)
	{
		k=0;
		u=0;
		for(j=0;j<m;j++)
		{
			if(Matrix[i][j]==0) u++;
			else k++;
		}
		sol+=1ll*pow(2,u)-1;
		sol+=1ll*pow(2,k)-1;
	}
	for(j=0;j<m;j++)
	{
		k=0;
		u=0;
		for(i=0;i<n;i++)
		{
			if(Matrix[i][j]==0) u++;
			else k++;
		}
		sol+=1ll*pow(2,u)-1-u;
		sol+=1ll*pow(2,k)-1-k;
	}
	printf("%lld\n",sol);
	return 0;
}