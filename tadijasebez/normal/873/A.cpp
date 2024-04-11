#include <stdio.h>
const int N=105;
int a[N],sol;
int main()
{
	int n,k,x,i;
	scanf("%i %i %i",&n,&k,&x);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i;i--)
	{
		if(n-i<k && x<a[i]) sol+=x;
		else sol+=a[i];
	}
	printf("%i\n",sol);
	return 0;
}