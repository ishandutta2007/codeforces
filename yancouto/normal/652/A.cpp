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
	ll h1, h2, a, b;
	scanf("%I64d %I64d", &h1, &h2);
	scanf("%I64d %I64d", &a, &b);
	for(int d = 0; d < 1000000; d++) {
		if(d) h1 += a * 4ll;
		h1 += 8ll * a;
		//if(h1 < h2 && h1 + 8ll * a >= h2) { printf("%d\n", d); return 0; }
		if(h1 >= h2) { printf("%d\n", d); return 0; }
		h1 -= b * 12ll;
	}
	puts("-1");
}