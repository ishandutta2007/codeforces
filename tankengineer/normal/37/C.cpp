#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int n;
vector<int> cnt[N];
string ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		cnt[t1].push_back(i);
	}
	int bar = 2;
	string last;
	for (int i = 1; i <= 1000; ++i) {
		if (cnt[i].size() > bar) {
			printf("NO\n");
			return 0;
		}
		for (int j = 0; j < (int)cnt[i].size(); ++j) {
			string now = last;
			if (now.size()) {
				for (int j = now.size() - 1; j >= 0; --j) {
					if (now[j] == '1') {
						now[j] = '0';
					} else {
						now[j] = '1';
						break;
					}
				}
			}
			while (now.size() < i) {
				now += '0';
			}
			ans[cnt[i][j]] = now;
			last = now;
		}
		bar -= cnt[i].size();
		bar = min(bar * 2, n);
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%s\n", ans[i].c_str());
	}
	return 0;
}