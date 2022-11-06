#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
int n, q;

int st[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[node] = 1; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = st[node << 1] + st[(node << 1) + 1];
}
void update(int node, int i, int L, int R, int val) {
	if (i < L || i > R) return;
	if (L == R) {st[node] += val; return;}
	update(node << 1, i, L, (L + R) >> 1, val);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
	st[node] = st[node << 1] + st[(node << 1) + 1];
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node];
	return query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
}

void solve() {
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	int cur = 1, dir = 1, len = n;
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int p; scanf("%d", &p);
			if (2 * p <= len) {
				cur += p * dir;
				FOR(i, 0, p) {
					int u = cur - (i + 1) * dir;
					int v = cur + i * dir;
					if ((u - cur + p * dir) * (u - cur - (len - p - 1) * dir) > 0) break;
					if ((v - cur + p * dir) * (v - cur - (len - p - 1) * dir) > 0) break;
					int r = query(1, u, u, 1, n);
					update(1, v, 1, n, r);
				}
				len -= p;
			}
			else {
				cur += (p - 1) * dir;
				FOR(i, 0, p) {
					int u = cur - i * dir;
					int v = cur + (i + 1) * dir;
					if ((u - cur + (p - 1) * dir) * (u - cur - (len - p) * dir) > 0) break;
					if ((v - cur + (p - 1) * dir) * (v - cur - (len - p) * dir) > 0) break;
					int r = query(1, v, v, 1, n);
					update(1, u, 1, n, r);
				}
				dir *= -1;
				len = p;
			}
		}
		else {
			int l, r; scanf("%d%d", &l, &r); r--;
			if (dir == -1) {
				l = -l; r = -r;
				swap(l, r);
			}
			int ans = query(1, cur + l, cur + r, 1, n);
			printf("%d\n", ans);
		}
	}
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