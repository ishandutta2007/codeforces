#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n;
int cnt[5] = {}; //0: 00, 1: 11, 2: 01, 3: 10
int rev[5] = {}; // 2: numbers of 01 that can reverse, 3: ...
int can2[200200] = {};
int can3[200200] = {};
string a[202000] = {};
int len[200200] = {};

map <string, bool> mp;

int main () {
	int T = read();
	while (T--) {
		mp.clear();
		cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0, rev[2] = rev[3] = 0;
		int i, j, k;
		n = read();
		string x;
		for (i = 1; i <= n; i++) {
			cin >> x; a[i] =x ; len[i] = x.size();
			j = x[0] - '0';
			k = x[len[i] - 1] - '0';
			if (j == 0 && k == 0) cnt[0]++;
			if (j == 1 && k == 1) cnt[1]++;
			if (j == 1 && k == 0) cnt[3]++, mp[x] = true;
			if (j == 0 && k == 1) cnt[2]++, mp[x] = true;
		}
		if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] + cnt[3] == 0) {
			puts("-1");
			continue;
		}
		for (i = 1; i <= n; i++) {
			x = a[i];
			reverse(x.begin(), x.end());
			if (a[i][0] != a[i][len[i] - 1] && !mp[x]) {
				if (a[i][0] - '0' == 0) rev[2]++, can2[rev[2]] = i;
				else rev[3]++, can3[rev[3]] = i;
			}
		}
		int ans = 0;
		if (cnt[2] < cnt[3]) {
			while (cnt[3] - cnt[2] >= 2) {
				if (rev[3] == 0) {
					ans = -1;
					break;
				}
				rev[3]--;
				cnt[3]--;
				cnt[2]++;
				ans++;
			}
			if (ans == -1) { puts("-1"); continue; }
			printf("%d\n", ans);
			for (i = 1; i <= ans; i++) printf("%d ", can3[i]); putchar('\n'); 
		}
		else {
			while (cnt[2] - cnt[3] >= 2) {
				if (rev[2] == 0) {
					ans = -1;
					break;
				}
				rev[2]--;
				cnt[2]--;
				cnt[3]++;
				ans++;
			}
			if (ans == -1) { puts("-1"); continue; }
			printf("%d\n", ans);
			for (i = 1; i <= ans; i++) printf("%d ", can2[i]); putchar('\n'); 
		}
	}
	return 0;
}