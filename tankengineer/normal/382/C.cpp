#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
vector<int> c, ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		c.push_back(a);
	}
	sort(c.begin(), c.end());
	if (n == 1) {
		printf("-1\n");
		return 0;
	} else if (n == 2) {
		int delta = c[1] - c[0];	
		ans.push_back(c[0] - delta);
		if (delta % 2 == 0) {
			ans.push_back(c[0] + delta / 2);
		}
		ans.push_back(c[1] + delta);
	} else {
		int delta1 = c[1] - c[0], cnt1 = 1, delta2, pos2, cnt2 = -1;
		for (int i = 2; i < n; ++i) {
			if (c[i] - c[i - 1] == delta1) {
				++cnt1;
			} else if (cnt2 == -1) {
				delta2 = c[i] - c[i - 1];
				pos2 = i;
				cnt2 = 1;
			} else if (c[i] - c[i - 1] == delta2) {
				++cnt2;
			}
		}
		if (cnt2 == -1) {
			ans.push_back(c[0] - delta1);
			ans.push_back(c.back() + delta1);
		} 
		if (cnt2 == 1 && cnt1 + cnt2 == n - 1) {
			if (delta2 == delta1 * 2) {
				ans.push_back(c[pos2] - delta1);
			}
		} 
		if (cnt1 == 1 && cnt1 + cnt2 == n - 1) {
			if (delta1 == delta2 * 2) {
				ans.push_back(c[0] + delta2);
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", (int)ans.size());
	if (ans.size()) {
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d%c", (int)ans[i], " \n"[i == (int)ans.size() - 1]);
		}
	}
	return 0;
}