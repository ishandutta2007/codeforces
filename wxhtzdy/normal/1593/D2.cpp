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
const int M = 2e6 + 5;


int n;
int a[N];
int mn[M];
vector<int> divs[M];

vector<int> get_divs(int x) {
	if (x == 0) return {0};
	vector<int> ret;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ret.pb(i);
			if (i * i != x) {
				ret.pb(x / i);
			}
		}
	}
	return ret;
}

int main()
{
	//ll total = 0;
	//for (int i = 1; i < M; i++) total += M / i;
	//printf("%lld", total);
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int need = n / 2;
		sort(a, a + n);
		bool found = false;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (a[i] == a[j]) {
					cnt += 1;
				}
			}
			if (cnt >= need) {
				printf("-1\n");
				found = true;
				break;
			}
		}
		if (found) {
			continue;
		}
		int ans = 0;
		for (int i = 0; i + need <= n; i++) {
			map<int, int> cnt;
			for (int j = i; j < n; j++) {
				int diff = a[j] - a[i];
				for (int x : get_divs(diff)) {
					cnt[x]++;
				}
			}
			for (auto thru : cnt) {
				if (thru.fi == 0) continue;
				if (cnt[0] + thru.se >= need) ans = max(ans, thru.fi);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}