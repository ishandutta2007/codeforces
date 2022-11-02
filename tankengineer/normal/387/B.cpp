#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	vector<int> target, cur;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		target.push_back(a);
	}
	sort(target.begin(), target.end());
	reverse(target.begin(), target.end());
	for (int i = 0; i < m; ++i) {
		int a;
		scanf("%d", &a);
		cur.push_back(a);
	}
	sort(cur.begin(), cur.end());
	reverse(cur.begin(), cur.end());
	int ans = n, j = 0;
	for (int i = 0; i < n; ++i) {
		if (j < m && cur[j] >= target[i]) {
			--ans;
			++j;
		}
	}
	printf("%d\n", ans);
	return 0;
}