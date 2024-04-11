#include <stdio.h>
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	int minsol=1,maxsol;
	if(k==n || k==0) minsol=0;
	if(k<=n/3) maxsol=2*k;
	else maxsol=n-k;
	printf("%i %i",minsol,maxsol);
	return 0;
}