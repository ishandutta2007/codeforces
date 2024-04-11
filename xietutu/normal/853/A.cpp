#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
priority_queue<pii> Q;
const int maxn = 300010;
int n, k, c[maxn], t[maxn];
LL ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	LL ret = 0;
	for (int i = 1; i <= k; ++i) {
		Q.push(pii(c[i], i));
		ans += 1LL * (k - i) * c[i];
		ret += c[i];
	}
	for (int i = k + 1; i <= k + n; ++i) {
		ans += ret;
		if (i <= n) {
			Q.push(pii(c[i], i));
		}
		ret -= Q.top().first;
		int no = Q.top().second;
		t[no] = i;
		Q.pop();
		if (i <= n) ret += c[i];
	}
	printf("%I64d\n", ans);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", t[i], i == n ? '\n' : ' '); 
}