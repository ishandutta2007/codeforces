#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char s[16];
		scanf("%s", s);
		vector<pair<int, int> > ans;
		for (int i = 1; i <= 12; ++i) {
			if (12 % i != 0) {
				continue;
			}
			bool flag = false;
			for (int j = 0; j < 12 / i; ++j) {
				bool tmp = true;
				for (int k = j; k < 12; k += 12 / i) {
					if (s[k] == 'O') {
						tmp = false;
					}
				}
				flag = flag || tmp;
			}
			if (flag) {
				ans.push_back(make_pair(i, 12 / i));
			}
		}
		printf("%d", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf(" %dx%d", ans[i].first, ans[i].second);
		}
		printf("\n");
	}
	return 0;
}