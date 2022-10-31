#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
int a[112345];

int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	vector<int> v;
	for(i = 1; i <= m; i++) {
		if(!binary_search(a, a + n, i))
			m -= i, v.pb(i);
	}
	printf("%d\n", (int) v.size());
	for(int x : v) printf("%d ", x);
	putchar('\n');
}