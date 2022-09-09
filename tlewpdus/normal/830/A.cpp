#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k, p;
ll a[1010], b[2010];

int main() {
    int i, j; ll mini = 1LL<<50;

	scanf("%lld%lld%lld",&n,&k,&p);
	for (i=0;i<n;i++) scanf("%lld",&a[i]);
	for (i=0;i<k;i++) scanf("%lld",&b[i]);
	sort(a,a+n); sort(b,b+k);
	for (i=0;i<=k-n;i++) {
		ll maxi = 0;
		for (j=i;j<i+n;j++) {
			maxi = max(maxi,abs(a[j-i]-b[j])+abs(b[j]-p));
		}
		mini = min(mini,maxi);
	}
	printf("%lld\n",mini);

    return 0;
}