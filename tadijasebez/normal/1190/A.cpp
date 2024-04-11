#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
ll a[N];
int main()
{
	int m;
	ll n,k;
	scanf("%lld %i %lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]),a[i]--;
	int ptr=1,ans=0;
	while(ptr<=m)
	{
		ans++;
		ll page=(a[ptr]-ptr+1)/k;
		int i;
		for(i=ptr+1;i<=m;i++)
		{
			ll p=(a[i]-ptr+1)/k;
			if(p>page) break;
		}
		ptr=i;
	}
	printf("%i\n",ans);
	return 0;
}