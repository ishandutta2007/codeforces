#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 101000;
int n, k, a[maxn];
typedef long long ll;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	ll l = 0, r = n;
	while (l + 1 < r) {
		ll mid = (l + r) / 2;
		if (mid * (mid + 1) / 2 >= k) r = mid;
		else l = mid;
	}
	ll ret = k - r * (r - 1) / 2;
	printf("%d\n", a[ret]);
}