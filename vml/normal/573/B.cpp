#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>
#include <unordered_set>
 
using namespace std;

const int maxn = (int)1e5 + 10;

int v[maxn];
int cnt[maxn];

int main() {
	int n;

	scanf("%d", &n);
	v[0] = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	v[n + 1] = 0;
	n += 2;

	int ans = 0;
	int now = 1;

	for (int i = 1; i <= n; i++) {
		now = min(now, v[i]);
		cnt[i] = now;
		now++;
	}

	now = 1;

	for (int i = n; i >= 1; i--) {
		now = min(now, v[i]);
		cnt[i] = min(cnt[i], now);
		now++;
	}

	for (int i = 1; i <= n; i++) {
		ans = max(ans, cnt[i]);
	}

	cout << ans << endl;

	return 0;
}