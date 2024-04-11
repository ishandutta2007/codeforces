#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s, ss;
int n, cnt[26], ans[26];

int main() {
	cin >> s >> n;
	for (int i = 0; i < s.size(); ++i) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < n; ++i) {
		int best = -1;
		for (int j = 0; j < 26; ++j) {
			if (cnt[j] == 0) {
				continue;
			}
			if (best == -1 || (cnt[j] * ans[best] > cnt[best] * ans[j])) {
				best = j;
			}
		}
		++ans[best];
		ss = ss + (char)('a' + best);
	}
	int bar = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 0) {
			continue;
		}
		if (ans[i] == 0) {
			bar = -1;
			break;
		}
		bar = max(bar, (cnt[i] + ans[i] - 1) / ans[i]);
	}
	if (bar == -1) {
		printf("%d\n", -1);
	} else {
		printf("%d\n%s\n", bar, ss.c_str());
	}
	return 0;
}