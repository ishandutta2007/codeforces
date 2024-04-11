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

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int aa = max((a > b ? 0 : b - a + 1), (a > c ? 0 : c - a + 1));
		int bb = max((b > a ? 0 : a - b + 1), (b > c ? 0 : c - b + 1));
		int cc = max((c > a ? 0 : a - c + 1), (c > b ? 0 : b - c + 1));
		printf("%d %d %d\n", aa, bb, cc);
	}
	return 0;
}