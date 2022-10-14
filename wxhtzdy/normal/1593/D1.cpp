#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 45;

int n;
int a[N];

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		if (a[0] == a[n - 1]) {
			printf("-1\n");
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = __gcd(ans, a[i] - a[0]);
		}
		printf("%d\n", ans);
	}
	return 0;
}