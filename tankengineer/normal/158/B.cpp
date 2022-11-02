#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int cnt[5];
	memset(cnt, 0, sizeof(cnt));
	int t1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t1);
		cnt[t1]++;
	}
	int ans = cnt[4];
	t1 = min(cnt[3], cnt[1]);
	ans += t1;
	cnt[3] -= t1;
	cnt[1] -= t1;
	ans += cnt[3];
	ans += (cnt[2] * 2 + cnt[1] + 3) / 4;
	cout << ans << endl;
	return 0;
}