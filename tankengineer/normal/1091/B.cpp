#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	vector<pair<int, int> > p(n), d(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &d[i].first, &d[i].second);
	}
	sort(p.begin(), p.end());
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());
	pair<int, int> ans = make_pair(p[0].first + d[0].first, p[0].second + d[0].second);
	printf("%d %d\n", ans.first, ans.second);
	for (int i = 0; i < n; ++i) {
		assert(p[i].first + d[i].first == ans.first);
		assert(p[i].second + d[i].second == ans.second);
	}
	return 0;
}