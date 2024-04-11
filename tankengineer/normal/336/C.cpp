#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005;
int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int v = 30; v >= 0; --v) {
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (a[i] >> v & 1) {
				ans.push_back(a[i]);
			}
		}
		if (ans.size() == 0) {
			continue;
		}
		int asum = ans[0];
		for (int i = 0; i < ans.size(); ++i) {
			asum &= ans[i];
		}
		if ((asum % (1 << v)) == 0) {
			printf("%d\n", (int)ans.size());
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
			}
			return 0;
		}
	}
	return 0;
}