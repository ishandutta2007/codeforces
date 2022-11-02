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

const int N = 1123;
int S[N], sz[N], w[N], b[N];
vector<int> cj[N];

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

inline void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
	for(int x : cj[b]) cj[a].pb(x);
}

vector<int> hd;
int memo[N][N];

int solve(int i, int W) {
	if(W < 0) return INT_MIN;
	if(i == hd.size()) return 0;
	int &r = memo[i][W];
	if(r != -1) return r;
	r = solve(i + 1, W);
	int tw = 0, tb = 0;
	for(int x : cj[hd[i]]) {
		tw += w[x]; tb += b[x];
		r = max(r, b[x] + solve(i + 1, W - w[x]));
	}
	r = max(r, tb + solve(i + 1, W - tw));
	return r;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j, m, W, a, b;
	rd(n); rd(m); rd(W);
	for(i = 0; i < n; i++) rd(w[i]);
	for(i = 0; i < n; i++) rd(::b[i]);
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, cj[i].pb(i);
	for(i = 0; i < m; i++) {
		rd(a); rd(b);
		join(a-1, b-1);
	}
	for(i = 0; i < n; i++)
		if(find(i) == i)
			hd.pb(i);
	printf("%d\n", solve(0, W));
}