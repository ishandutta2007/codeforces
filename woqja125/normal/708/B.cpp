#include<stdio.h>
int main()
{
	int a00, a01, a10, a11;
	int n0=-1, n1=-1;
	scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
	//1000000000
	for(int i=1; 1ll*i*(i-1)/2<=a00 || 1ll*i*(i-1)/2<=a11; i++)
	{
		if(1ll*i*(i-1)/2 == a00) n0 = i;
		if(1ll*i*(i-1)/2 == a11) n1 = i;
	}
	if(n1 == -1 || n0 == -1)
	{
		printf("Impossible");
		return 0;
	}
	if(a00==0 && a01==0 && a10==0 && a11==0)
	{
		printf("1");
		return 0;
	}
	if(a00 == 0 && a01 == 0 && a10 == 0)
	{
		for(int i=1; i<=n1; i++)printf("1");
		return 0;
	}
	if(a01==0 && a10==0 && a11==0)
	{
		for(int i=1; i<=n0; i++)printf("0");
		return 0;
	}
	int N = n0+n1;
	if(1ll*N*(N-1)/2 != 0ll+a00+a01+a10+a11)
	{
		printf("Impossible");
		return 0;
	}
	for(int i=1; i<=N; i++)
	{
		if(a01 >= n1 && n0 != 0)
		{
			printf("0");
			n0--;
			a01 -= n1;
		}
		else
		{
			printf("1");
			n1--;
			a10 -= n0;
		}
	}
	return 0;
}