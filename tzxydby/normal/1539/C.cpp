#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,s;
long long a[N],k,x,d[N];
int main()
{
	scanf("%d%lld%lld",&n,&k,&x);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	for(int i=1;i<n;i++)
	{
		long long h=max(0LL,(d[i]+x-1)/x-1);
		if(k<h)
			break;
		s++;
		k-=h;
	}
	printf("%d\n",n-s);
	return 0;
}