#include <bits/stdc++.h>
using namespace std;
#define ct first
#define sum second
typedef long long ll;
typedef pair<ll, ll> pii;
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
const int N = 1123456;


vector<ll> query[N];
vector<pii> ans[N];


int A[N]; ll H[N], l[N];
ll acc[N], tmp[N]; int tn;

void dfs(int u, ll d) {
	if(u > n) return;
	tmp[tn++] = d;
	dfs(2 * u, d + l[2 * u]);
	dfs(2 * u + 1, d + l[2 * u + 1]);
}


void answer_for(int u) {
	tn = 0;
	dfs(u, 0);
	sort(tmp, tmp + tn);
	acc[0] = tmp[0];
	for(int i = 1; i < tn; i++)
		acc[i] = acc[i - 1] + tmp[i];
	sort(query[u].begin(), query[u].end());
	ans[u].resize(query[u].size());
	for(int i = int(query[u].size()) - 1; i >= 0; i--) {
		while(tn > 0 && tmp[tn - 1] > query[u][i])
			tn--;
		ans[u][i] = pii(tn, tn? acc[tn - 1] : 0ll);
	}
}

inline void reg(int u, ll v) { query[u].pb(v); }
inline pii get(int u, ll v) { return ans[u][lower_bound(query[u].begin(), query[u].end(), v) - query[u].begin()]; }




int main() {
	int m;
	int i;
	rd(n); rd(m);
	for(i = 2; i <= n; i++) rd(l[i]);
	
	for(i = 0; i < m; i++) {
		rd(A[i]); rd(H[i]);
		int ai = A[i]; ll hi = H[i];
		reg(ai, hi);
		int nx = ai;
		hi -= l[ai]; ai = ai / 2;
		while(ai && hi > 0) {
			reg(ai, hi);
			if(hi - l[nx] > 0) reg(nx, hi - l[nx]);
			nx = ai;
			hi -= l[ai]; ai = ai / 2;
		}
	}
	for(int i = 1; i <= n; i++) answer_for(i);

	for(i = 0; i < m; i++) {
		int ai = A[i]; ll hi = H[i];
		pii ans = get(ai, hi);
		int nx = ai;
		hi -= l[ai]; ai = ai / 2;
		while(ai && hi > 0) {
			pii p = get(ai, hi);
			ans.ct += p.ct;
			ans.sum += p.ct * (H[i] - hi) + p.sum;
			if(hi - l[nx] > 0) {
				pii p = get(nx, hi - l[nx]);
				ans.ct -= p.ct;
				ans.sum -= p.ct * (H[i] - hi + l[nx]) + p.sum;
			}
			nx = ai;
			hi -= l[ai]; ai = ai / 2;
		}
		printf("%lld\n", ans.ct * H[i] - ans.sum);
	}
}