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
	ll s, x; int i;
	scanf("%I64d %I64d", &s, &x);
	s -= x;
	if(s < 0) { puts("0"); return 0; }
	bool z = true;
	for(i = 0; i < 61; i++)
		if(!(x & (1ll << i)) && (s & (1ll << (i + 1))))
			s ^= (1ll << (i + 1)), z = false;
	if(s) puts("0");
	else printf("%I64d\n", (1ll << __builtin_popcountll(x)) - ll(z? 2 : 0));
}