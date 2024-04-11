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

const int N = 112345;

vector<int> base[N];
ll p2[N];

int main() {
	int i, j;
	int n, q;
	rd(n); rd(q);
	vector<int> cur;
	p2[0] = 1;
	for(i = 1; i <= n; i++) p2[i] = mod(2ll * p2[i - 1]);
	for(i = 0; i < n; i++) {
		int x; rd(x);
		int y = x;
		for(int z : cur)
			if((y ^ z) < y)
				y ^= z;
		if(y) {
			cur.pb(y);
			sort(cur.begin(), cur.end(), greater<int>());
		}
		base[i] = cur;
	}
	while(q--) {
		int l, x;
		rd(l); rd(x); l--;
		for(int z : base[l])
			if((x ^ z) < x)
				x ^= z;
		if(x) puts("0");
		else
			printf("%lld\n", p2[l + 1 - base[l].size()]);
	}
}