#include <bits/stdc++.h>
#define pb push_back
#define sz(x)(int)x.size()
#define all(x)x.begin(),x.end()
 
using ll = long long;
using namespace std;

const int N = 2e5 + 55;
const int LOG = 17;
const int MOD = 1e9 + 7;
const int MEM = 10 * 1000000;
const int T = 1 << 18;

int lson[MEM], rson[MEM], dp[MEM], fre, root[N];

int build(int l = 0, int r = T - 1) {
	int v = fre++;
	dp[v] = 1;
	if (l == r) return v;
	int m = l + r >> 1;
	lson[v] = build(l, m);
	rson[v] = build(m + 1, r);
	return v;
}	

int Set(int x, int y, int u, int l = 0, int r = T - 1) {
	int v = fre++;
	if (l == r) {
		dp[v] = y;
		return v;
	}
	int m = l + r >> 1;
	lson[v] = lson[u];
	rson[v] = rson[u];
	if (x <= m)
		lson[v] = Set(x, y, lson[u], l, m);
	else
		rson[v] = Set(x, y, rson[u], m + 1, r);
	dp[v] = 1LL * dp[lson[v]] * dp[rson[v]] % MOD;
	return v;
}

int qq(int x, int y, int v, int l = 0, int r = T - 1) {
	if (x <= l && r <= y) return dp[v];
	int m = l + r >> 1;
	int res = 1;
	if (x <= m) res = 1LL * res * qq(x, y, lson[v], l, m) % MOD;
	if (m < y) res = 1LL * res * qq(x, y, rson[v], m + 1, r) % MOD;
	return res;
}
		
map <int, int> last;

const int MaxN = 1 << 17;
struct ff {
	int cnt[MaxN];
	int Max[2 * MaxN];
	void build() {
		for (int i = 0; i < MaxN; ++i)
			Max[i + MaxN] = cnt[i];
		for (int i = MaxN - 1; 1 <= i; --i)
			Max[i] = max(Max[2 * i], Max[2 * i + 1]);
	}
	int qq(int l, int r) {
		int res = 0;
		for (l += MaxN, r += MaxN + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) res = max(res, Max[l++]);
			if (r & 1) res = max(res, Max[--r]);
		}
		return res;
	}
} F[90];

int n, q, a[N], powers[100][20];	
bool s[N];
vector <int> P;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for (int i = 2; i < N; ++i) {
		if (!s[i]) {
			if (1LL * i * i <= N)
				P.pb(i);
			for (int j = i; j < N; j += i)
				s[j] = 1;
		}
	}
	
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j < sz(P); ++j) {
			int cnt = 0;
			while (a[i] % P[j] == 0) {
				cnt++;
				a[i] /= P[j];
			}
			F[j].cnt[i] = cnt;
		}
	}
	for (int j = 0; j < sz(P); ++j) {
		F[j].build();
		powers[j][0] = 1;
		for (int i = 1; i < 20; ++i)
			powers[j][i] = 1LL * powers[j][i - 1] * P[j] % MOD;
	}
	
	root[0] = build();
	for (int i = 1; i <= n; ++i) {
		root[i] = root[i - 1];
		if (last.find(a[i]) != last.end()) 
			root[i] = Set(last[a[i]], 1, root[i]);
		root[i] = Set(i, a[i], root[i]);
		last[a[i]] = i;
	}
	
	int z = 0;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x = (x + z) % n + 1;
		y = (y + z) % n + 1;
		if (x > y) swap(x, y);
		z = 1;
		for (int i = 0; i < sz(P); ++i) 
			z = 1LL * z * powers[i][F[i].qq(x, y)] % MOD;
		z = 1LL * z * qq(x, y, root[y]) % MOD;
		cout << z << endl;
	}
	
	return 0;
}