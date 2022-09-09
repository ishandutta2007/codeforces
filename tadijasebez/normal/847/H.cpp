#include <stdio.h>
const int N=100050;
long long sol,a[N];
int main()
{
	int n,l,r,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld\n",&a[i]);
	l=1,r=n;
	while(l<r)
	{
		while(l<r && a[l]<a[l+1]) l++;
		while(r>l && a[r]<a[r-1]) r--;
		if(l==r) break;
		if(a[l]<a[r]) sol+=a[l]-a[l+1]+1,a[l+1]=a[l]+1;
		else sol+=a[r]-a[r-1]+1,a[r-1]=a[r]+1;
	}
	printf("%lld\n",sol);
	return 0;
}