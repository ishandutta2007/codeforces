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
ull l[100009];
int main() {
	int i, n;
	scanf("%d", &n);
	ll tot = 0;
	for(i = 0; i < n; i++)
		scanf("%I64u", &l[i]);
	sort(l, l + n, greater<ull>());
	ull st[100009]; int sn = 0;
	for(i = 0; i < n - 1; i++) {
		if((l[i] - l[i + 1]) > 1) continue;
		st[sn++] = l[i + 1]; i++;
	}
	for(i = 0; i < sn - 1; i += 2)
		tot += st[i] * st[i + 1];
	printf("%I64u\n", tot);
}