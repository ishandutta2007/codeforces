#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int n, m, tx, ty;
	bool usex[1005], usey[1005];
	memset(usex, 0, sizeof(usex));
	memset(usey, 0, sizeof(usey));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &tx, &ty);
		usex[tx] = true;
		usey[ty] = true;
	}
	int ans = 0;
	for (int i = 2; n - i + 1 >= i; ++i) {
		if (n - i + 1 == i) {
			if (!usex[i] || !usey[i]) ++ans;
		} else {
			int cnt = 0 + !usex[i] + !usey[i] + !usex[n - i + 1] + !usey[n - i + 1];
			//cout << i << ' ' << cnt << endl;
			ans += cnt;
		}
	}
	printf("%d\n", ans);
	return 0;
}