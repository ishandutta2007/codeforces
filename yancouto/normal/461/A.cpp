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

ull a[300009];
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%I64u", &a[i]);
	ull tot = 0;
	sort(a, a + n, greater<ull>());
	for(i = 1; i < n; i++)
		a[i] += a[i-1];
	tot = a[n-1];
	for(i = n - 1; i > 0; i--)
		tot += a[i];
	printf("%I64u\n", tot);
}