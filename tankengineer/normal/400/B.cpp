#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[1005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		int tmp = 0;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'G') {
				tmp -= j;
			} else if (s[j] == 'S') {
				tmp += j;
			}
		}
		ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	if (*ans.begin() < 0) {
		printf("-1\n");
	} else {
		printf("%d\n", (int)ans.size());
	}
	return 0;
}