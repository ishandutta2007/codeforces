#include <stdio.h>
int main()
{
    int n,k,i,a[105],r=0;
    scanf("%i%i",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
    }
	for(i=0;i<n;i++)
	{
		if(a[i]>0 && a[i]>=a[k-1]) r++;
	}
	printf("%i",r);
    return 0;
}