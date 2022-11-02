#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005;
int cnt[N];
char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i + 3 < n; ++i) {
		cnt[i + 1] = cnt[i];
		if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
			++cnt[i + 1];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 4; j <= n; ++j) {
			if (cnt[j - 3] - cnt[i]) {
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}