#include<cstdio>
using namespace std;
int cnt[200001];
int main() {
	int n, ans = 1, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		cnt[t]++;
	}
	for (int i = 0; i <= n; i++) {
		if (cnt[i] >= 2) ans += cnt[i] - 1;
	}
	printf("%d\n", ans);
	return 0;
}