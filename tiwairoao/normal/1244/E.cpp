#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
typedef long long ll;
ll S[MAXN + 5], a[MAXN + 5], k;
int n;
bool check(ll x) {
	for(int i=1;i<=n;i++) {
		ll y = a[i] + x;
		int p = upper_bound(a + 1, a + n + 1, y) - a;
		ll c = (S[n] - S[p - 1]) - (n - p + 1)*y;
		c = c + (i - 1)*a[i] - S[i - 1];
		if( c <= k ) return true;
		y = a[i] - x;
		p = lower_bound(a + 1, a + n + 1, y) - a - 1;
		c = (S[n] - S[i]) - (n - i)*a[i];
		c = c + p*y - S[p];
		if( c <= k ) return true;
	}
	return false;
}
int main() {
	scanf("%d%lld", &n, &k);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i=1;i<=n;i++) S[i] = S[i-1] + a[i];
	ll le = 0, ri = a[n] - a[1];
	while( le < ri ) {
		ll mid = (le + ri) >> 1;
		if( check(mid) ) ri = mid;
		else le = mid + 1;
	}
	printf("%lld\n", ri);
}