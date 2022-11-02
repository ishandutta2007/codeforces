#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int n, k, l, m, a[210000];
long long sum[210000], ans;

int main() {
	scanf("%d%d%d", &n, &k, &l);
	// for (int i = 1)
	m = n * k;
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a +  m + 1);
	int tt = 1;
	while (tt <= m && abs(a[tt]) - abs(a[1]) <= l)
		tt ++;
	tt--;
	if (tt < n) {
		printf("0\n");
		return 0;
	}
	ans = 0;
	for (int i = 1; i <= m; i++)
		sum[i] = sum[i - 1] + a[i];
	long long tmp = 0;
	int cnt = n;
	for (int i = 1; i <= tt; i += k) {
		cnt --;
		tmp += a[i];
		if (i + cnt <= tt && i + k + cnt > tt)
			ans = max(ans, tmp + sum[tt] - sum[tt - cnt]);
	}
	printf("%I64d\n", ans);
}