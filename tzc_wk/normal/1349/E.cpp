#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN = 2e5;
int n, m, dp[MAXN + 5][2], res[MAXN + 5], nxt[MAXN + 5][2];
ll t[MAXN + 5]; pii p[MAXN + 5];
ll calcsum(int l, int r) {return 1ll * (l + r) * (r - l + 1) / 2;}
int findmin(ll s, int l, int r) {
	int L = 0, R = r - l + 1, p = 0;
	while (L <= R) {
		int mid = L + R >> 1;
		if (calcsum(r - mid + 1, r) >= s) p = mid, R = mid - 1;
		else L = mid + 1;
	}
	return p;
}
bool checksum(ll s, int l, int r) {
	if (s < 0 || s > calcsum(l, r)) return 0;
	return s >= calcsum(l, l + findmin(s, l, r) - 1);
}
void findsum(ll s, int l, int r) {
	int p = findmin(s, l, r); s -= calcsum(l, l + p - 1);
	for (int i = l + p - 1; i >= l; i--) {
		if (s > (r - l + 1) - p) s -= (r - l + 1) - p, res[i + (r - l + 1) - p] = 1;
		else res[i + s] = 1, s = 0;
	}
}
int main() {
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &t[n - i + 1]);
	vector<pair<ll, int> > vec;
	for (int i = 1; i <= n; i++) if (t[i]) vec.pb(mp(t[i], i));
	for (int i = 0, j; i < vec.size(); i = j) {
		j = i; while (j < vec.size() && vec[j].fi >= vec[i].fi) ++j;
		p[++m] = mp(vec[i].se, vec[j - 1].se);
	}
	if (!m) {for (int i = 1; i <= n; i++) printf("0"); return 0;}
	memset(dp, 0xcf, sizeof(dp)); dp[m + 1][1] = n + 1; p[m + 1].fi = n + 1;
	p[0].se = -1;
	for (int i = m; i; i--) {
		for (int j = 0; j < 2; j++) {
			if (j == 0 && t[p[i].fi] != t[p[i].se] && i != 1) continue;
			if (j == 1 && (p[i].fi != p[i].se && t[p[i].fi] == t[p[i].se])) continue;
			for (int k = 0; k < 2; k++) {
				if (dp[i + 1][k] > p[i].se) {
					ll nd = (t[p[i].fi] - (!j)) - (t[p[i + 1].fi] - (!k));
					int L = p[i].se + 1, R = dp[i + 1][k] - 1;
					int cl = (j) ? p[i].fi : (p[i - 1].se + 1), cr = (j) ? p[i].fi : ((i == 1) ? p[i].se : p[i].fi);
					for (int l = cr; l >= cl; l--) {
						if (checksum(nd - l, L, R)) {
							if (j == 0 && t[l]) continue;
							if (dp[i][j] < l) {dp[i][j] = l; nxt[i][j] = k;}
							break;
						}
					}
				}
			}
		}
	}
	int curi = 1, curj = (dp[1][1] >= 0);
	while (curi <= m) {
		res[dp[curi][curj]] = 1;
		int L = p[curi].se + 1, R = dp[curi + 1][nxt[curi][curj]] - 1;
		ll nd = (t[p[curi].fi] - (!curj)) - (t[p[curi + 1].fi] - (!nxt[curi][curj]));
		findsum(nd - dp[curi][curj], L, R);
		curj = nxt[curi][curj]; ++curi;
	}
	for (int i = 1; i <= n; i++) printf("%d", res[n - i + 1]);
	return 0;
}