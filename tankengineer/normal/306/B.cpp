#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 200005;
int n, m, a[M], l[M];
bool use[M];

bool cmp(const int i, const int j) {
	return a[i] == a[j] ? l[i] > l[j] : a[i] < a[j];
}

int main() {
	scanf("%d%d", &n, &m);
	vector<int> v;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", a + i, l + i);
		v.push_back(i);
	}
	sort(v.begin(), v.end(), cmp);
	int maxdis = -1, maxnum = -1, nowdis = -1;
	for (int _ = 0; _ < v.size(); ++_) {
		int i = v[_];
		if (a[i] > maxdis) {
			if (nowdis != maxdis) {
				use[maxnum] = true;
			}
			use[i] = true;
			maxdis = nowdis = a[i] + l[i] - 1;
			maxnum = i;
		} else if (a[i] > nowdis + 1) {
			nowdis = maxdis;
			use[maxnum] = true;
			if (a[i] + l[i] - 1 > maxdis) {
				maxdis = a[i] + l[i] - 1;
				maxnum = i;
			}
		} else {
			if (a[i] + l[i] - 1 > maxdis) {
				maxdis = a[i] + l[i] - 1;
				maxnum = i;
			}
		}
	}
	if (maxdis != nowdis) {
		use[maxnum] = true;
	}
	vector<int> ans;
	for (int i = 0; i < m; ++i) {
		if (!use[i]) {
			ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d%c", ans[i] + 1, i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}