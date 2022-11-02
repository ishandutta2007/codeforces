#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int cnt[5005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	vector<int> ans;
	for (int i = 0; i < 5005; ++i) {
		if (cnt[i]) {
			--cnt[i];
			ans.push_back(i);
		}
	}
	for (int i = ans.back() - 1; i >= 0; --i) {
		if (cnt[i]) {
			--cnt[i];
			ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d%c", ans[i], " \n"[i == (int)ans.size()]);
	}
	return 0;
}