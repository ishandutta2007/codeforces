#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int t,n,a[N];
long long s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=0;
		for(int i=1;i<=n+1;i++)
			s+=abs(a[i]-a[i-1]);
		for(int i=1;i<=n;i++)
			s-=max(a[i]-max(a[i-1],a[i+1]),0);
		printf("%lld\n",s);
	}
	return 0;
}