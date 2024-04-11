#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 500010;
int n;
int a[maxn];
map<int, vi> g;
int nxt[maxn];
int prv[maxn];

int st[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[node] = prv[L]; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return INF;
	if (l <= L && r >= R) return st[node];
	return min(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}
void update(int node, int i, int L, int R) {
	if (i < L || i > R) return;
	if (L == R) {st[node] = INF; return;}
	update(node << 1, i, L, (L + R) >> 1);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}

void solve() {
	ms(nxt, -1); ms(prv, 0x3f);
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		g[a[i]].push_back(i);
	}
	for (map<int, vi>::iterator it = g.begin(); it != g.end(); it++) {
		vi tmp = it->second;
		FOR(i, 0, sz(tmp) - 1) {
			nxt[tmp[i]] = tmp[i + 1];
			prv[tmp[i + 1]] = tmp[i];
		}
	}
	build(1, 0, n - 1);
	vi ans;
	int last = 0, cur = 0;
	while (cur < n) {
		if (prv[cur] >= n || prv[cur] < last) {cur++; continue;}
		if (query(1, prv[cur] + 1, cur - 1, 0, n - 1) < prv[cur]) {
			FOR(i, prv[cur] + 1, cur) if (prv[i] < prv[cur]) {
				ans.push_back(a[prv[i]]);
				ans.push_back(a[prv[cur]]);
				ans.push_back(a[i]);
				ans.push_back(a[cur]);
				break;
			}
			FOR(i, last, cur + 1) {
				if (nxt[i] != -1) {
					update(1, nxt[i], 0, n - 1);
					prv[nxt[i]] = INF;
				}
			}
			last = cur + 1;
		}
		else if (prv[cur] < n && prv[cur] >= last && prv[prv[cur]] < n && prv[prv[cur]] >= last && prv[prv[prv[cur]]] < n && prv[prv[prv[cur]]] >= last) {
			ans.push_back(a[prv[prv[prv[cur]]]]);
			ans.push_back(a[prv[prv[cur]]]);
			ans.push_back(a[prv[cur]]);
			ans.push_back(a[cur]);
			FOR(i, last, cur + 1) {
				if (nxt[i] != -1) {
					update(1, nxt[i], 0, n - 1);
					prv[nxt[i]] = INF;
				}
			}
			last = cur + 1;
		}
		cur++;
	}
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%d ", ans[i]);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}