#include <bits/stdc++.h>
using namespace std;
vector<int> ___[200001];
int __[200001];
set<int> a,_;
map<int, pair<int, int>> m;
int main() {
	int k,i,j;
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		_.clear();
		int n,x;
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &x);
			___[i].push_back(x);
			__[i] += x;
		}
		for (j = 0; j < ___[i].size();j++) {
			int wtf = ___[i][j];
			if (a.find(__[i] - wtf) != a.end()) {
				printf("YES\n%d %d\n%d %d", i + 1, j + 1, m[__[i] - wtf].first + 1, m[__[i] - wtf].second + 1);
				getchar(); getchar();
				return 0;
			}
			_.insert(__[i]-wtf);
			m[__[i] - wtf] = make_pair(i,j);
		}
		for (auto wtf : _) {
			a.insert(wtf);
		}
	}
	printf("NO");
}