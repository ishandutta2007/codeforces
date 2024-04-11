#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, f[N];

bool used[N];

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		if (!f[i]) {
			for (int j = i; j <= n; j += i) {
				f[j] = i;
			}
		}
	}
	vector<pair<int, int> > ans;
	for (int i = n; i >= 2; --i) {
		if (f[i] == i) {
			vector<int> tmp;
			int j = i;
			do {
				if (!used[j]) {
					tmp.push_back(j);
				}
				j += i;
			} while (j <= n);
			if (tmp.size() == 1) {
				continue;
			}
			if (tmp.size() % 2 == 1) {
				swap(tmp[1], tmp[tmp.size() - 1]);
			}
			for (int i = 0; i + 1 < tmp.size(); i += 2) {
				int u = tmp[i], v = tmp[i + 1];
				used[u] = used[v] = true;
				ans.push_back(make_pair(u, v));
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}