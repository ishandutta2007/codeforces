#include <stdio.h>
#include <cmath>
#define ll long long
const int N=100050;
int a[N],v[N],L[N],R[N];
ll sol;
int main()
{
	int n,q,i,l,r;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),v[i-1]=fabs(a[i]-a[i-1]);
	while(q--)
	{
		scanf("%i %i",&l,&r);r--;
		sol=0;
		L[l]=l-1;
		R[r]=r+1;
		for(i=l+1;i<=r;i++)
		{
			L[i]=i-1;
			while(L[i]>=l && v[L[i]]<v[i]) L[i]=L[L[i]];
		}
		for(i=r-1;i>=l;i--)
		{
			R[i]=i+1;
			while(R[i]<=r && v[R[i]]<=v[i]) R[i]=R[R[i]];
		}
		for(i=l;i<=r;i++) sol+=(ll)(i-L[i])*(R[i]-i)*v[i];
		printf("%lld\n",sol);
	}
	return 0;
}