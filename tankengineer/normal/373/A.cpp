#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[5];
int cnt[9];

int main() {
	int k;
	scanf("%d", &k);
	k <<= 1;
	for (int i = 0; i < 4; ++i) {
		scanf("%s", s);
		for (int j = 0; j < 4; ++j) {
			if (s[j] == '.') {
				continue;
			}
			++cnt[s[j] - '1'];
		}
	}
	for (int i = 0; i < 9; ++i) {
		if (cnt[i] > k) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}