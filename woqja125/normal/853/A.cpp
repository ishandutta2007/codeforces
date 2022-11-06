#include<stdio.h>
#include<queue>
using namespace std;
int c[300001];
int r[300001];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	priority_queue<pair<int, int>> H;
	for (int i = 1; i <= k; i++) {
		H.emplace(c[i], i);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i + k <= n) H.emplace(c[i + k], i + k);
		ans += 1ll * (i + k - H.top().second)*H.top().first;
		r[H.top().second] = i + k;
		H.pop();
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++)printf("%d ", r[i]);
	return 0;
}