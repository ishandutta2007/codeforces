#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long LL;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXD = 1000000;
const int MAXN = 100010;
int n, m, K, minv[MAXN];
LL suf[MAXD + 1];
LL ans;
vector<pii> a[MAXD + 1], b[MAXD + 1];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; ++i) {
		int d, f, t, c;
		scanf("%d%d%d%d", &d, &f, &t, &c);
		if (t == 0) a[d].PB(pii(f, c));
		else b[d].PB(pii(t,	c));
	}
	
	memset(minv, 0x3f, sizeof minv);
	memset(suf, 0x3f, sizeof suf);
	int cnt = 0;
	LL ret = 0;
	for (int i = MAXD; i >= 1; --i) {
		for (auto item : b[i]) {
			int no = item.first, value = item.second;
			if (minv[no] == inf) ++cnt;
			else ret -= minv[no];
			
			minv[no] = min(minv[no], value);
			ret += minv[no];
		}
		if (cnt == n) suf[i] = ret;
	}
	
	memset(minv, 0x3f, sizeof minv);
	cnt = 0;
	ret = 0;
	ans = INF;
	for (int i = 1; i <= MAXD; ++i) {
		for (auto item : a[i]) {
			int no = item.first, value = item.second;
			if (minv[no] == inf) ++cnt;
			else ret -= minv[no];
			
			minv[no] = min(minv[no], value);
			ret += minv[no];
		}
		if (cnt == n && i + K + 1 <= MAXD && suf[i + K + 1] != INF) {
			ans = min(ans, suf[i + K + 1] + ret);
		}
	}
	if (ans < INF) printf("%I64d\n", ans);
	else puts("-1");
}