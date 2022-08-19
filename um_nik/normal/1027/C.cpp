#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)1e6 + 7;
int n;
ll a[N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	ll bp = (ll)1e9, bq = 1;
	ll bx = -1, by = -1;
	ll lst = -1;
	int L = 0;
	while(L < n) {
		int R = L + 1;
		while(R < n && a[L] == a[R]) R++;
		if (R - L >= 4) {
			printf("%lld %lld %lld %lld\n", a[L], a[L], a[L], a[L]);
			return;
		}
		if (R - L >= 2) {
			ll x = a[L];
			if (lst != -1) {
				ll p = (x + lst) * (x + lst);
				ll q = x * lst;
				//eprintf("! %lld %lld %lld %lld\n", lst, x, p, q);
				if (p * bq < q * bp) {
					bp = p;
					bq = q;
					bx = lst;
					by = x;
				}
			}
			lst = x;
		}
		L = R;
	}
	printf("%lld %lld %lld %lld\n", bx, bx, by, by);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}