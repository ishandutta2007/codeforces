#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char c[13][13];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int it = 0; it < t; it++) {
		vector <pair <int, int> > ans;
		string s;
		cin >> s;
		for (int i = 1; i <= 12; i++) {
			if (12 % i == 0) {
				for (int j = 0; j < 12; j++) {
					c[j / i][j % i] = s[j];
				}
				for (int j = 0; j < i; j++) {
					bool yes = true;
					for (int k = 0; k < 12 / i; k++) {
						if (c[k][j] != 'X') {
							yes = false;
							break;
						}
					}
					if (yes) {
						ans.push_back(make_pair(12 / i, i));
						break;
					}
				}
			}
		}
		printf("%d", (int)ans.size());
		sort(ans.begin(), ans.end());
		for (int j = 0; j < (int)ans.size(); j++) {
			printf(" %dx%d", ans[j].first, ans[j].second);
		}
		printf("\n");
	}
	return 0;
}