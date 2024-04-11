#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, p[maxn], a[maxn];
bool visit[maxn];
typedef long long LL;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", p + i);
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) {
			int x = i, cnt = 0;
			while (!visit[x]) {
				++cnt; visit[x] = true; x = p[x];
			}
			a[++m] = cnt;
		}
	sort(a + 1, a + m + 1, greater<int>() );
	if (m == 1) cout << 1LL * n * n << endl;
	else {
		LL ret = 1LL * (a[1] + a[2]) * (a[1] + a[2]);
		for (int i = 3; i <= m; ++i)
			ret += 1LL * a[i] * a[i];
		cout << ret << endl;
	}
}