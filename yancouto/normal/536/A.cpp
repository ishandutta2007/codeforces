#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

ll acc[1000009];
int a[1000009];
int main() {
	int i, A, B, n, m, l, t, j;
	scanf("%d %d %d", &A, &B, &n);
	for(i = 1; i < 1000003; i++) {
		a[i] = A + (i-1) * B;
		acc[i] += a[i] + acc[i-1];
		if(a[i] > 1000000) break;
	}
	int mx = i;
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &l, &t, &m);
		if(l >= mx || a[l] > t) { puts("-1"); continue; }
		ll v = t; v = v * m; ll tot = a[l];
		int p = upper_bound(a + l, a + mx, t) - a;
		int p2 = upper_bound(acc + l, acc + p, v + acc[l - 1]) - acc;
		printf("%d\n", p2 - 1);
	}
}