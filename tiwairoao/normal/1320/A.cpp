#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1000000;

ll c[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		c[x + n - i] += x;
	}
	ll ans = 0;
	for(int i=0;i<=MAXN;i++)
		ans = max(ans, c[i]);
	printf("%lld\n", ans);
}