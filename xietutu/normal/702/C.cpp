#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 200010;
typedef long long LL;
int n, m, tot, a[maxn], b[maxn];
pii c[maxn];
bool visit[maxn];
bool check(int r) {
	static int Q[maxn];
	int h = 0, t = 0;
	memset(visit, 0, sizeof visit);
	for (int i = 1; i <= tot; ++i) 
		if (c[i].second <= n) {
			while (h < t && c[i].first - Q[h + 1] > r) ++h;
			if (h < t) visit[c[i].second] = true;
		}
		else Q[++t] = c[i].first;
	
	for (int i = tot; i >= 1; --i) 
		if (c[i].second <= n) {
			while (h < t && Q[h + 1] - c[i].first > r) ++h;
			if (h < t) visit[c[i].second] = true;
		}
		else Q[++t] = c[i].first;
	
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) return false;
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		c[++tot] = make_pair(a[i], i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
		c[++tot] = make_pair(b[i], i + n);
	}
	sort(c + 1, c + tot + 1);
	
	LL l = -1, r = 2e9+7;
	while (l + 1 < r) {
		LL mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%I64d\n", r);
}