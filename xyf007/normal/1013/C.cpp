#include<bits/stdc++.h>
using namespace std;
long long n,a[20000001];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=2*n;i++)
	  scanf("%lld",&a[i]);
	sort(a+1,a+2*n+1);
	long long ans1=(a[n]-a[1])*(a[2*n]-a[n+1]),minn=1e9+7;
	for(int i=2;i<=n;i++)
	  if(a[i+n-1]-a[i]<minn)
	    minn=a[i+n-1]-a[i];
	printf("%lld",min(ans1,minn*(a[2*n]-a[1])));
	return 0;
}