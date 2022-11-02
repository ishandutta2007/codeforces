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

int n, m, g;
const int M = 1123456;
int c[M], cl[M], nc[M], ncv[M], t;

int S[M], sz[M];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

inline void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
}

int main() {
	int i, j, x;
	rd(n); rd(m);
	for(i = 1; i <= m; i++) c[i] = 1;
	int en = 2;
	for(i = 0; i < n; i++) {
		rd(g);
		map<int, int> mp;
		for(j = 0; j < g; j++) {
			rd(x);
			mp[x]++;
		}
		map<int, vector<int>> cl;
		for(pii e : mp)
			cl[e.snd].pb(e.fst);
		for(auto e : cl) {
			t++;
			for(int y : e.snd) {
				if(nc[c[y]] < t) nc[c[y]] = t, ncv[c[y]] = en++;
				c[y] = ncv[c[y]];
			}
		}
	}
	for(i = 1; i <= m; i++) S[i] = i, sz[i] = 1;
	for(i = 1; i <= m; i++)
		if(cl[c[i]]) join(cl[c[i]], i);
		else cl[c[i]] = i;
	ll tot = 1;
	for(i = 1; i <= m; i++)
		if(find(i) == i)
			for(j = 1; j <= sz[i]; j++)
				tot = mod(tot * ll(j));
	printf("%lld\n", tot);
}