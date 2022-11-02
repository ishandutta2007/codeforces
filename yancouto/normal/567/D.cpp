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

int main() {
	int i, n, k, a, m, x;
	set<int> s;
	scanf("%d %d %d %d", &n, &k, &a, &m);
	s.insert(0); s.insert(n + 1);
	int tot = (n + 1) / (a + 1);
	bool ok = true;
	for(i = 0; i < m; i++) {
		scanf("%d", &x);
		set<int>::iterator it = s.lower_bound(x);
		int r = *it;
		int l = *(--it);
		tot -= (r - l) / (a + 1);		
		s.insert(x);
		tot += (x - l) / (a + 1);
		tot += (r - x) / (a + 1);
		if(ok && tot < k) {
			ok = false;
			printf("%d\n", i + 1);
		}
	}
	if(ok) puts("-1");
	return 0;
}