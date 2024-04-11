#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

int n, cnt[310000], pre_sum[310000], ss[2];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		long long x;
		scanf("%I64d", &x);
		for (int j = 0; j <= 62; j++) {
			if ((1LL << j) & x)
				cnt[i]++;
		}
	}
	pre_sum[0] = 0;
	ss[0] = 1;
	for (int i = 1; i <= n; i++) {
		pre_sum[i] = (pre_sum[i - 1] + cnt[i]);
		ans += ss[pre_sum[i] % 2];
		int ma = cnt[i];
		for (int j = i - 1; j >= i - 100 && j >= 0; j--) {
			if (ma * 2 > (pre_sum[i] - pre_sum[j]) && pre_sum[i] % 2 == pre_sum[j] % 2)
				ans--;
			ma = max(ma, cnt[j]);
		}
		ss[pre_sum[i] % 2]++;
	}
	printf("%I64d\n", ans);
}