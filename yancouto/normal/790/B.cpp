#include <bits/stdc++.h>
using namespace std;
#define t first
#define S second
typedef long long ll;
typedef pair<ll, ll> pii;
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

int n; ll k;

struct info {
	vector<pii> v;
	info() {
		for(int i = 0; i < k; i++) v.pb(pii(0, 0));
	}
	void join(info, ll);
};

ll tot = 0;

void info::join(info o, ll h) {
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++) {
			int left = (i + j - 2 * (h % k) + k * 100) % k;
			if(left) left = k - left;
			ll add = v[i].S * o.v[j].t + v[i].t * o.v[j].S + ll(left - 2ll * h) * v[i].t * o.v[j].t;
			assert(add >= 0 && (add % k) == 0);
			tot += add / k;
		}
	for(int i = 0; i < k; i++)
		v[i].t += o.v[i].t,
		v[i].S += o.v[i].S;
}

const int N = 212345;
vector<int> adj[N];

info dfs(int u, int p, int h) {
	info x;
	x.v[h % k] = pii(1, h);
	for(int v : adj[u]) {
		if(v == p) continue;
		x.join(dfs(v, u, h + 1), h);
	}
	return x;
}

int main() {
	int i, a, b;
	rd(n); rd(k);
	for(i = 0; i < n; i++) {
		rd(a); rd(b); a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(0, -1, 0);
	printf("%lld\n", tot);
}