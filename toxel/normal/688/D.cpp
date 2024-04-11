#include<stdio.h>
#include<string.h>
#include<math.h>
#define N (1000001)
int n,k,k1,c[N],prime[N],factor[N],i,j,m;
bool flag;
int main()
{
	memset(factor,0,sizeof(int));
	for (i=0;i<N;i++)
		prime[i]=1;
	scanf("%d%d",&n,&k);
	for (i=0;i<n;i++)
		scanf("%d",&c[i]);
	for (i=2;i<=1000;i++)
		if (prime[i])
			for (j=i;i*j<N;j++)
				prime[i*j]=0;
	k1=k;
	for (i=2;k>1;i++)
	{
		if (prime[i])
			while (!(k%i))
			{
				k/=i;
				factor[i]++;
			}
	}
	k=k1;
	for (i=2;i<=k;i++)
		if (factor[i])
		{
			flag=false;
			m=1;
			for (j=0;j<factor[i];j++)
				m*=i;
			for (j=0;j<n;j++)
				if (!(c[j]%m))
				{
					flag=true;
					break;
				}
			if (!flag)
			{
				printf("No");
				return 0;
			}
		}
	printf("Yes");
	return 0;
}