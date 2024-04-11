#include <stdio.h>
int w[100000];
int main()
{
	int n,k,sum=0,i;
	scanf("%i%i",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%i",&w[i]);
		if(w[i]%k==0) w[i]/=k;
		else w[i]=w[i]/k+1;
		sum+=w[i];
	}
	if(sum%2==0) sum/=2;
	else sum=sum/2+1;
	printf("%i",sum);
	return 0;
}