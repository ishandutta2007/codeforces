#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	long long p = 2, k = 1;
	for(k=1; k<=n; k++)
	{
		int r;
		for(int i=1; ; i++)
		{
			r = 1ll*i*i;
			if(1llu*r*r*k*(k+1)*(k+1) >= p) break;
		}
		printf("%llu\n", 1llu*r*r*k*(k+1)*(k+1)-p);
		p = r*k;
	}
	return 0;
}