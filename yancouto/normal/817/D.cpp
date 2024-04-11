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
#	define debug(args...) {}
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

const int N = 2123456;
int L[N], R[N], sz[N], a[N], p[N];

ll go(int u) {
	if(!u) return 0;
	ll vall = go(L[u]);
	ll valr = go(R[u]);
	sz[u] = 1 + sz[L[u]] + sz[R[u]];
	return vall + valr + ll(a[u]) * ll(sz[L[u]] + 1) * ll(sz[R[u]] + 1);
}

int main() {
	int i, j;
	rd(n);
	int xmn = 0, xmx = 0;
	for(i = 1; i <= n; i++) {
		rd(a[i]); a[i + n] = a[i];
		int ymn = 0, ymx = 0;
		while(xmx && a[xmx] < a[i]) {
			ymx = xmx;
			xmx = p[xmx];
		}
		L[i] = ymx;
		if(xmx != 0) R[xmx] = i, p[i] = xmx;
		xmx = i;
		while(xmn && a[xmn] > a[i]) {
			ymn = xmn;
			xmn = p[xmn];
		}
		L[i + n] = ymn;
		if(xmn != 0) R[xmn] = i + n, p[i + n] = xmn;
		xmn = i + n;
	}
	while(p[xmx]) xmx = p[xmx];
	while(p[xmn]) xmn = p[xmn];
	ll mx = go(xmx);
	ll mn = go(xmn);
	printf("%lld\n", mx - mn);
}