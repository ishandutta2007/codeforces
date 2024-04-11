#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	vector<int> c;
	c.push_back(x);
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		if (m == 2) {
			m = 1;
		} else {
			m = 2;
		}
		for (int j = 0; j < m; ++j) {
			int a;
			scanf("%d", &a);
			c.push_back(a);
		}
	}
	vector<int> a = c;
	a.push_back(0);
	sort(a.begin(), a.end());
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i + 1 < (int)a.size(); ++i) {
		int delta = a[i + 1] - a[i] - 1;
		ans1 += (delta + 1) / 2;
		ans2 += delta;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}