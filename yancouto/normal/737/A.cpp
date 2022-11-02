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

template<class num> inline void read(num &x) {
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
const int N = 212345;
int c[N], g[N], acc[N], v[N];

int main() {
	int i, j, k, s, t;
	read(n);
	read(k);
	read(s);
	read(t);
	for(i = 0; i < n; i++) {
		read(c[i]);
		read(v[i]);
	}
	for(i = 1; i <= k; i++) read(g[i]);
	g[k + 1] = s; k++;
	sort(g, g + k + 1);
	for(i = k; i > 0; i--) g[i] -= g[i - 1];
	sort(g + 1, g + k + 1);
	for(i = 1; i <= k; i++) acc[i] = g[i] + acc[i - 1];
	int mn = INT_MAX;
	for(i = 0; i < n; i++) {
		if(g[k] > v[i]) continue;
		int p = upper_bound(g + 1, g + k + 1, v[i] / 2) - g;
		ll aa = acc[p - 1] + ll(acc[k] - acc[p - 1]) * 3ll - ll(v[i]) * ll(k - p + 1);
		if(aa <= t) mn = min(mn, c[i]);
	}
	if(mn == INT_MAX) mn = -1;
	printf("%d\n", mn);
}