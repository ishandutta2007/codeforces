#include <stdio.h>
int a[100050],n,i;
int main()
{
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	i=n-1;
	while(i>0 && a[i]<a[i+1]) i--;
	printf("%i\n",i);
	return 0;
}