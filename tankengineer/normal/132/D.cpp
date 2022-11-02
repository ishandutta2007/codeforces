#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;
char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	vector<pair<char, int> > ans;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			continue;
		}
		int j = i - 1;
		do {
			++j;
			while (j < n & s[j] == '1') {
				++j;
			}
		} while (j + 1 < n && s[j + 1] == '1');
		vector<int> one, zero;
		for (int k = i; k < j; ++k) {
			if (s[k] == '1') {
				one.push_back(k);
			} else {
				zero.push_back(k);
			}
		}
		if (zero.size() + 2 < one.size()) {
			ans.push_back(make_pair('+', n - i));
			for (int k = 0; k < (int)zero.size(); ++k) {
				ans.push_back(make_pair('-', n - 1 - zero[k]));
			}
			ans.push_back(make_pair('-', n - j));
		} else {
			for (int k = 0; k < (int)one.size(); ++k) {
				ans.push_back(make_pair('+', n - 1 - one[k]));
			}
		}
		i = j;
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%c2^%d\n", ans[i].first, ans[i].second);
	}
	return 0;
}