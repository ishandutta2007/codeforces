#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
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
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
const int K = 350;
int n, q;
int a[maxn];
deque<int> dq[K];
int cnt[K][maxn];

int get(int k) {
	int d = k / K;
	int r = k % K;
	return dq[d][r];
}

int insert(int k, int val) {
	int d = k / K;
	int r = k % K;
	dq[d].insert(dq[d].begin() + r, val);
}

void erase(int k) {
	int d = k / K;
	int r = k % K;
	dq[d].erase(dq[d].begin() + r);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		dq[i / K].pb(a[i]);
		cnt[i / K][a[i]]++;
	}
	scanf("%d", &q);
	int lastans = 0;
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int l, r; scanf("%d%d", &l, &r);
			l = (l + lastans - 1) % n;
			r = (r + lastans - 1) % n;
			if (l > r) swap(l, r);
			int t = get(r); erase(r);
			int lo = (l + K - 1) / K * K;
			int hi = r / K * K;
			for (int i = lo; i <= hi; i += K) {
				if (i > l) {
					int u = (i - 1) / K;
					int t = dq[u].back();
					cnt[u][t]--;
					cnt[u + 1][t]++;
					dq[u].pop_back();
					dq[u + 1].pf(t);
				}
			}
			insert(l, t);
			cnt[l / K][t]++;
			cnt[r / K][t]--;
		}
		else {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			l = (l + lastans - 1) % n;
			r = (r + lastans - 1) % n;
			k = (k + lastans - 1) % n + 1;
			if (l > r) swap(l, r);
			lastans = 0;
			int u = (l + K - 1) / K;
			int v = r / K;
			FOR(i, u, v) lastans += cnt[i][k];
			FOR(i, l, min(r + 1, u * K)) lastans += get(i) == k;
			if (u <= v) FOR(i, max(l, v * K), r + 1) lastans += get(i) == k;
			printf("%d\n", lastans);
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