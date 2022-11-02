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

int n, s, a[3100000];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int k = (n + 1) / 2;
	long long ans = 0;
	ans += abs(a[k] - s);
	for (int i = 1; i < k; i++)
		if (a[i] > s)
			ans += abs(a[i] - s);
	for (int i = k + 1; i <= n; i++)
		if (a[i] < s)
			ans += abs(a[i] - s);
	cout << ans << endl;
}