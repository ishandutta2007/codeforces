#include <stdio.h>
int a[1000];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	if(a[0]%2==0 || a[n-1]%2==0 || n%2==0) printf("No\n");
	else printf("Yes\n");
	return 0;
}