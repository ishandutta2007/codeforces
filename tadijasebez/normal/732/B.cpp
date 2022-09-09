#include <stdio.h>
const int N=505;
int sol,a[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=2;i<=n;i++)
	{
		if(a[i]+a[i-1]<k)
		{
			sol+=k-a[i-1]-a[i];
			a[i]=k-a[i-1];
		}
	}
	printf("%i\n",sol);
	for(i=1;i<=n;i++) printf("%i ",a[i]);
	return 0;
}