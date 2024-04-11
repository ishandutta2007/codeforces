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

int ps[] = {2, 3, 5, 7, 11, 13, 17, 19};

int ct(int i, int cur, int mx) {
	if(i < 0) return 1;
	int pi = 1;
	int c = 0;
	for(; cur * pi <= mx; pi *= ps[i])
		c += ct(i - 1, cur * pi, mx);
	return c;
}

int k;
void build(int i, int cur, int mx) {
	if(i < 0) {
		printf("%d ", cur);
		if(--k == 0) { putchar('\n'); exit(0); }
		return;
	}
	int pi = ps[i];
	for(; cur * pi <= mx; pi *= ps[i])
		build(i - 1, cur * pi, mx);
	build(i - 1, cur, mx);
}

int main() {
	int i;
	scanf("%d", &k);
	for(i = 0;; i++) {
		if(ct(i, 1, 2 * k * k) >= k) {
			build(i, 1, 2 * k * k);
			return 0;
		}
	}
}