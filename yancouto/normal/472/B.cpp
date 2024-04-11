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

int a[2009];
int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	int t = 0;
	int p = 0;
	while(p < n) {
		t += 2 * (a[p] - 1);
		p += k;
	}
	printf("%d\n", t);
}