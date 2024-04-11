#include <stdio.h>
const int N=1050;
int a[N];
int main()
{
	int n,i,l,r;
	scanf("%i",&n);l=1;r=n;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	int c=0;
	int sum[2];sum[0]=sum[1]=0;
	while(l<=r)
	{
		if(a[l]>a[r]) sum[c]+=a[l++];
		else sum[c]+=a[r--];
		c^=1;
	}
	printf("%i %i\n",sum[0],sum[1]);
	return 0;
}