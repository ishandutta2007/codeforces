#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int N = 1111111;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> A[N], B[N];
int n, m, K;
ll tot, C[N], pre[N];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; ++i) {
		int d, f, t, c;
		scanf("%d%d%d%d", &d, &f, &t, &c);
		if (t == 0) {
			A[d].pb(mp(f, c));
		} else B[d].pb(mp(t, c));
	}
	tot = 1e12 * n;
	for (int i = 1; i <= n; ++i) C[i] = 1e12;
	pre[0] = tot;
	for (int i = 1; i <= 1000000; ++i) {
		pre[i] = pre[i - 1];
		for (int j = 0; j < A[i].size(); ++j) {
			int p = A[i][j].X, c = A[i][j].Y;
			tot -= C[p];
			C[p] = min(C[p], (ll)c);
			tot += C[p];
		}
		pre[i] = tot;
	}
	tot = 1e12 * n; ll ans = 1e12 * n;
	for (int i = 1; i <= n; ++i) C[i] = 1e12;
	for (int i = 1000000; i > K; --i) {
		for (int j = 0; j < B[i].size(); ++j) {
			int p = B[i][j].X, c = B[i][j].Y;
			tot -= C[p];
			C[p] = min(C[p], (ll)c);
			tot += C[p];
		}
		ans = min(tot + pre[i - K - 1], ans);
	}
	if (ans <= 1e11) cout << ans << endl;
	else puts("-1");
	return 0;
}