#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	int a, b;
	scanf("%d%d", &a, &b);
	vector<pair<int, int> > c;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		c.push_back(make_pair(x * a + y * b, i + 1));
	}
	sort(c.begin(), c.end());
	vector<int> ans;
	for (int i = 0; i < (int)c.size(); ++i) {
		if (d >= c[i].first) {
			d -= c[i].first;
			ans.push_back(c[i].second);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}