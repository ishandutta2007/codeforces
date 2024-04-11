#include<stdio.h>
int main()
{
	int n, k, i, s=0;
	scanf("%d%d", &n, &k);
	for(i=0; s+k<=240 && i<=n; s+=i*5)i++;
	printf("%d", i-1);
	return 0;
}