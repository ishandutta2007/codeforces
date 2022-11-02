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

int a[16000000];
bool used[16000000];
int n;

int gcd(int x, int y) {
	if (!x)
		return y;
	return gcd(y % x, x);
}

int main() {
	scanf("%d", &n);
	int ans = n + 1;
	int GCD = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[x] += 1;
		GCD = gcd(x, GCD);
	}
	for (int i = 2; i <= 15000000; i++)
		if (!used[i]) {
			for (int j = 2 * i; j <= 15000000; j += i)
				used[j] = true;
		}
	for (int i = 1; i <= 15000000; i++)
		if (i % GCD == 0 && i != GCD && !used[i / GCD]) {
		int cnt = 0;
		for (int j = i; j <= 15000000; j += i)
			cnt += a[j];
		if (cnt < n && cnt) {
			ans = min(ans, n - cnt);
		}
	}
	if (ans <= n) {
		printf("%d\n", ans);
	}else {
		printf("-1\n");
	}
}