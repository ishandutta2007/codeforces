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

const int N = 100009;
int a[N], l[N], r[N], d[N], accq[N];
ll acc[N];
int main() {
	int i, n, m, k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < m; i++)
		scanf("%d %d %d", &l[i], &r[i], &d[i]);
	for(i = 0; i < k; i++) {
		scanf("%d %d", &x, &y); x--;
		accq[x]++;
		accq[y]--;
	}
	ll s = 0;
	for(i = 0; i < m; i++) {
		s += accq[i];
		acc[l[i] - 1] += ll(d[i]) * s;
		acc[r[i]] -= ll(d[i]) * s;
	}
	s = 0;
	for(i = 0; i < n; i++) {
		s += acc[i];
		printf("%I64d ", s + ll(a[i]));
	}
	putchar('\n');
}