#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const ll mx=1e14;
ll a[N];
bool Check(int x, ll y)
{
	y+=x;
	ll p=(ll)(sqrt(y)+0.5);
	if(p*p==y) return 1;
	return 0;
}
ll sum[N];
int main()
{
	int n,i,j=1;
	scanf("%i",&n);
	for(i=2;i<=n;i+=2) scanf("%lld",&a[i]);
	ll tmp=j;
	for(i=1;i<=n;i+=2)
	{
		while(!Check(a[i+1],tmp))
		{
			j+=2;
			tmp+=j;
			if(tmp-sum[i-1]>mx) return 0*printf("No\n");
		}
		a[i]=tmp-sum[i-1];
		sum[i]=sum[i-1]+a[i];
		sum[i+1]=sum[i]+a[i+1];
		while(tmp<sum[i+1])
		{
			j+=2;
			tmp+=j;
		}
	}
	printf("Yes\n");
	for(i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}