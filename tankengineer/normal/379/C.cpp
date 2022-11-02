#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, ans[300005];

int main() {
	vector<pair<int, int> > v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	int least = 0;
	for (int i = 0; i < n; ++i) {
		least = max(least, v[i].first);
		ans[v[i].second] = least++;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}