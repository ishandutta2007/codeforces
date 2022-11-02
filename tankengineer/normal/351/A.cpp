#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int cnt0 = 0;
	vector<int> num;
	scanf("%d", &n);
	for (int i = 0; i < n * 2; ++i) {
		char s[20];
		scanf("%s", s);
		int l = strlen(s);
		int t = (s[l - 1] - '0') + 10 * (s[l - 2] - '0') + 100 * (s[l - 3] - '0');
		if (t == 0) {
			++cnt0;
		} else {
			num.push_back(t);
		}
	}
	sort(num.begin(), num.end());
	int ans = 2 * n * 1000;
	for (int i = 0; i <= cnt0 && i <= n; ++i) {
		int tmp = 1000 * (n - i);
		for (int j = 0; j < (int)num.size(); ++j) {
			tmp -= num[j];
		}
		ans = min(ans, abs(tmp));
	}
	printf("%.3f\n", (double)ans / 1000);
	return 0;
}