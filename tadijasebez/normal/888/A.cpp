#include <stdio.h>
const int N=1050;
int a[N],sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=2;i<n;i++)
	{
		if(a[i-1]<a[i] && a[i+1]<a[i]) sol++;
		else if(a[i-1]>a[i] && a[i+1]>a[i]) sol++;
	}
	printf("%i\n",sol);
	return 0;
}