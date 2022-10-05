#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
const int MAXN = 20;
const int MAXP = 1 << 20;
int n, lg[MAXP + 5], dp[MAXP + 5]; ll a[MAXN + 5], sum[MAXP + 5];
int bt[MAXN + 5], len = 0;
vector<ll> getseq(int l, int r) {
	if (l > r) return vector<ll>{0};
	vector<ll> v1 = getseq(l + 1, r), v2 = v1, v;
	int p1 = 0, p2 = 0, len = (1 << r - l);
	for (int i = 0; i < len; i++) v2[i] = v1[i] + a[bt[l]], v1[i] -= a[bt[l]];
	while (p1 < len || p2 < len) {
		if (p2 >= len || (p1 < len && v1[p1] < v2[p2])) v.push_back(v1[p1++]);
		else v.push_back(v2[p2++]);
	}
	return v;
}
bool check(int S) {
	if (__builtin_popcount(S) == 1 && !sum[S]) return 1;
	len = 0; for (int i = 1; i <= n; i++) if (S >> (i - 1) & 1) bt[++len] = i;
	if (sum[S] - len + 1 & 1) return 0; int mid = len >> 1;
	vector<ll> seq1 = getseq(1, mid);
	vector<ll> seq2 = getseq(mid + 1, len);
	int l1 = 1 << mid, l2 = 1 << len - mid; seq2.push_back(1e18);
	int nd = 1 + (abs(sum[S]) < len) * 2;
	for (int i = 0, L = l2, R = l2; i < l1; i++) {
		while (~R && seq1[i] + seq2[R] >= len) --R;
		while (~L && seq1[i] + seq2[L] > -len) --L; ++L;
		nd -= min(nd, R - L + 1);
	}
	return (nd == 0);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), lg[1 << i] = i;
	for (int i = 1; i < (1 << n); i++) sum[i] = sum[i & (i - 1)] + a[lg[i & (-i)] + 1];
	for (int i = 1; i < (1 << n); i++) if (!dp[i] && check(i)) {
		int rst = ((1 << n) - 1) ^ i;
		for (int j = rst; ; --j &= rst) {
			chkmax(dp[i | j], dp[j] + 1);
			if (!j) break;
		}
	}
	printf("%d\n", n - dp[(1 << n) - 1]);
	return 0;
}