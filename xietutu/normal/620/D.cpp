#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int maxn = 2005;
LL A, B, sum;
LL Abs(LL x) { return x > 0 ? x : -x; }
int n, m, a[maxn], b[maxn];
pair<LL, pii> aa[maxn * maxn], bb[maxn * maxn];
vector<pair<int, int> > G, F;
LL work(int n, int m) {	 
	sort(aa + 1, aa + n + 1);
	sort(bb + 1, bb + m + 1);
	LL ans = 1000000000000000LL;
	for (int i = 1; i <= n; ++i) {
		LL ret = A * 2 - aa[i].first, t = sum - ret, tmp; 
		int p = lower_bound(bb + 1, bb + m + 1, make_pair(t, pii(0, 0))) - bb;
		if (p <= m) {
			if ((tmp = ret + bb[p].first - sum) < ans) {
				ans = tmp; F[0] = aa[i].second; F[1] = bb[p].second;
			}
		}
		if (p > 1) {
			if ((tmp = sum - (ret + bb[p - 1].first)) < ans) {
				ans = tmp; F[0] = aa[i].second; F[1] = bb[p - 1].second;
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		A += a[i];
		aa[i] = make_pair(2LL * a[i], pii(i, 0));
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
		B += b[i];
		bb[i] = make_pair(2LL * b[i], pii(i, 0));
	}
	sum = A + B;
	F.resize(2);
	
	LL ans = Abs(A - B), t;
	if ((t = work(n, m)) < ans) ans = t, G = F;
	if (n > 1 && m > 1) {
		int nn = 0, mm = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				aa[++nn] = make_pair(2LL * (a[i] + a[j]), pii(i, j));
		for (int i = 1; i <= m; ++i)
			for (int j = i + 1; j <= m; ++j)
				bb[++mm] = make_pair(2LL * (b[i] + b[j]), pii(i, j));
		if ((t = work(nn, mm)) < ans) ans = t, G = F;
	}
	cout << ans << endl;
	if (G.size()) {
		if (G[0].second) cout << 2 << endl;
		else cout << 1 << endl;
		cout << G[0].first << " " << G[1].first << endl;
		if (G[0].second) cout << G[0].second << " " << G[1].second << endl;
	}
	else cout << 0 << endl;
}