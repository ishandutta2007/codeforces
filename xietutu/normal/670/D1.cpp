#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 101000;
int n, k, a[maxn], b[maxn];
typedef long long ll;
bool check(ll x) {
	long long ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret += max(0LL, 1LL * a[i] * x - b[i]);
		if (ret > k) return false;
	}
	return ret <= k;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
		
	for (int i = 1; i <= n; ++i) 
		scanf("%d", b + i);
	
	ll l = 0, r = 2 * (1e9) + 1;
	while (l + 1 < r) {
		ll mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%I64d\n", l);
}