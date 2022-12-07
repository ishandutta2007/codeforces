#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> vec[n];
		for (int i = 0; i < n; ++i)
			vec[i].push_back(0);
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			vec[--a].push_back(i);
		}
		int res = n;
		for (int i = 0; i < n; ++i) {
			vec[i].push_back(n + 1);
			if ((int)vec[i].size() == 2) continue;
			int cur = 0;
			for (int j = 0; j + 1 < vec[i].size(); ++j)
				cur += vec[i][j] + 1 != vec[i][j + 1];
			res = min(res, cur);
		}
		printf("%d\n", res);
	}
	return 0;
}