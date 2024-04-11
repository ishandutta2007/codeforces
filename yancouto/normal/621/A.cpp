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

int main() {
	int i, j, n, x;
	scanf("%d", &n);
	int lst = 0;
	ll tot = 0;
	int mn = INT_MAX;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x & 1) {
			mn = min(mn, x);
			if(lst) tot += lst + x, lst = 0;
			else lst = x;
		} else tot += x;
	}
	if(mn != INT_MAX && lst && mn < lst) tot += lst - mn;
	printf("%I64d\n", tot);
}