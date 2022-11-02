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

const int M = 212345;
vector<int> ps;

map<int, vector<int>> psl;

map<vector<int>, int> memo;
int solve(const vector<int> &f) {
	if(f.empty()) return 0;
	if(memo.count(f)) return memo[f];
	int &ans = memo[f];
	vector<int> seen;
	int mx = f.back();
	for(int i = 1; i <= mx; i++) {
		vector<int> g;
		for(int x : f)
			if(x > i)
				g.pb(x - i);
			else if(x < i)
				g.pb(x);
		if(g.empty()) { seen.pb(0); continue; }
		sort(g.begin(), g.end());
		g.erase(unique(g.begin(), g.end()), g.end());
		seen.pb(solve(g));
	}
	sort(seen.begin(), seen.end());
	seen.erase(unique(seen.begin(), seen.end()), seen.end());
	for(int i = 0; i < int(seen.size()); i++)
		if(seen[i] != i)
			return ans = i;
	return ans = int(seen.size());
}

int cp[M], a[M];

int main() {
	int i, j;
	rd(n);
	for(i = 2; i * i <= 1000000009; i++)
		if(!cp[i]) {
			ps.pb(i);
			for(ll j = i + i; j < M; j += i)
				cp[j] = 1;
		}

	for(i = 0; i < n; i++) {
		rd(a[i]);
		for(int p : ps) {
			int d = 0;
			for(; !(a[i] % p); d++) a[i] /= p;
			if(d > 0) psl[p].pb(d);
		}
		if(a[i] > 1) psl[a[i]].pb(1);
	}
	int x = 0;
	for(auto &e : psl) {
		vector<int> &f = e.snd;
		sort(f.begin(), f.end());
		f.erase(unique(f.begin(), f.end()), f.end());
		x ^= solve(f);
	}
	if(x) puts("Mojtaba");
	else puts("Arpa");
}