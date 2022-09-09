#include <stdio.h>
const int N=100050;
int a[N];
int main()
{
    int n,k,i;
    scanf("%i %i",&n,&k);
    for(i=1;i<=n;i++) scanf("%i",&a[i]);
    int sol=2;
    for(i=1;i<n;i++)
	{
		int d=a[i+1]-a[i];
		if(d==2*k) sol++;
		if(d>2*k) sol+=2;
	}
	printf("%i\n",sol);
    return 0;
}