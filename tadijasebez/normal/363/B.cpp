#include <stdio.h>
const int N=150050;
int a[N],tr,sol=1000000000,ans;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		tr+=a[i];
		if(i>=k)
		{
			tr-=a[i-k];
			if(tr<sol)
			{
				sol=tr;
				ans=i-k+1;
			}
		}
	}
	printf("%i\n",ans);
	return 0;
}