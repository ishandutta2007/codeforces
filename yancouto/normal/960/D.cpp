#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

ll vsh[100], nsh[100];

int main() {
	int q;
	rd(q);
	while(q--) {
		int t; ll x, k;
		rd(t); rd(x);
		int p = 63 - __builtin_clzll(x);
		assert((1ll << p) <= x && (1ll << (p + 1)) > x);
		if(t == 3) {
			ll rel = x - (1ll << p);
			//printf("rel %lld\n", rel);
			rel += vsh[p];
			//printf("rel %lld\n", rel);
			rel %= (1ll << p);
			x = rel + (1ll << p);
			while(true) {
				//printf("at [%d] vsh = %lld\n", p, vsh[p]);
				ll rel = x - (1ll << p);
				//printf("rel %lld\n", rel);
				rel += (1ll << p) - vsh[p];
				//printf("rel %lld\n", rel);
				rel %= (1ll << p);
				printf("%lld ", rel + (1ll << p));
				if(x == 1) assert(p == 0);
				if(x == 1) break;
				//printf("at [%d] nsh = %lld\n", p, nsh[p]);
				rel = x - (1ll << p);
				rel += nsh[p];
				rel %= (1ll << p);
				x = (1ll << p) + rel;
				//printf("new x %lld\n", x);
				x >>= 1; p--;
			}
			putchar('\n');
		} else {
			rd(k);
			ll &v = (t == 1? vsh[p] : nsh[p]);
			//printf("%s[%d] += %lld\n", (t == 1? "vsh" : "nsh"), p, k);
			v += k;
			v %= (1ll << p);
			if(v < 0) {
				v += (1ll << p);
				v %= (1ll << p);
			}
		}
	}
}