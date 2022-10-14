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

const int N = 400050;

int n, k;
int x[N];

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &x[i]);
		}
		sort(x, x + k);
		ll sum = 0;
		int ans = 0;
		for (int i = k - 1; i >= 0; i--) {
			if (sum < x[i]) {
				sum += n - x[i];
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}