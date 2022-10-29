#include <bits/stdc++.h>
using namespace std;

int x[5005], y[5005];
vector <int> ans[2][2];

int calc() {
	int rt = 0;
	for (int i = 0; i < 2; ++ i)
		for (int j = 0; j < 2; ++ j)
			if (!ans[i][j].empty()) ++ rt;
	return rt;
}

int main() {
	int n; scanf("%d", &n);
	
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
		ans[x[i] & 1][y[i] & 1].push_back(i);
	}
	
	while (calc() == 1) {
		if (x[1] & 1) {
			for (int i = 1; i <= n; ++ i) ++ x[i];
		}
		if (y[1] & 1) {
			for (int i = 1; i <= n; ++ i) ++ y[i];
		}
		for (int i = 1; i <= n; ++ i) {
			x[i] /= 2;
			y[i] /= 2;
		}
		for (int i = 0; i < 2; ++ i)
			for (int j = 0; j < 2; ++ j) ans[i][j].clear();
		for (int i = 1; i <= n; ++ i)
			ans[x[i] & 1][y[i] & 1].push_back(i);
	}
	if (ans[0][0].size() + ans[1][1].size() != 0 && ans[0][1].size() + ans[1][0].size() != 0) {
		printf("%d\n", (int)ans[0][0].size() + (int)ans[1][1].size());
		for (auto x : ans[0][0]) printf("%d ", x);
		for (auto x : ans[1][1]) printf("%d ", x);
		printf("\n");
	} else {
		if (ans[0][0].size() + ans[1][1].size() != 0) {
			printf("%d\n", (int)ans[0][0].size());
			for (auto x : ans[0][0]) printf("%d ", x);
			printf("\n");
		} else {
			printf("%d\n", (int)ans[0][1].size());
			for (auto x : ans[0][1]) printf("%d ", x);
			printf("\n");
		}
	}
	return 0;
}