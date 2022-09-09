#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll binom(int n, int k)
{
	ll ans=1;
	for(int i=n-k+1;i<=n;i++) ans*=i;
	for(int i=1;i<=k;i++) ans/=i;
	return ans;
}
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	ll ans=1;
	for(int i=k;i>=2;i--)
	{
        int mul=i==4?9:i==3?2:1;
        ans+=binom(n,i)*mul;
	}
	printf("%lld\n",ans);
	return 0;
}