#include<stdio.h>
#include<algorithm>
int a[1000];
int main()
{
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++)scanf("%d", &a[i]);
	std::sort(a+1, a+1+n);
	for(i=1; i<=n; i++)printf("%d ", a[i]);
	return 0;
}