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

int n;

inline ll sq(ll x) { return x * x; }
struct circ{
	ll x, y, r;
	bool operator < (circ o) const { return r < o.r; }
	inline ll dist(circ o) { return sq(x - o.x) + sq(y - o.y); }
} c[1123];
int mrk[1123];
vector<int> adj[1123];

ll memo[1123][3][3];
ll solve(int i, int p1, int p2) {
	ll &r = memo[i][p1 + 1][p2 + 1];
	if(r != -1) return r;
	ll ans1 = ll(p1) * sq(c[i].r), ans2 = ll(p2) * sq(c[i].r);
	for(int j : adj[i])
		ans1 += solve(j, -p1, p2),
		ans2 += solve(j, p1, -p2);
	return r = max(ans1, ans2);
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%lld %lld %lld", &c[i].x, &c[i].y, &c[i].r);
	sort(c, c + n);
	for(i = 1; i < n; i++)
		for(j = i - 1; j >= 0; j--) {
			if(!mrk[j] && c[i].dist(c[j]) <= sq(c[i].r - c[j].r)) {
				mrk[j] = 1;
				adj[i].pb(j);
			}
		}
	ll ans = 0;
	for(i = 0; i < n; i++)
		if(!mrk[i])
			ans += solve(i, 1, 1);
	printf("%.20f\n", ans * acos(-1));
}