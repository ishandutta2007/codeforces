#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 2020;

char ch[MAXN];
char s1[MAXN], s2[MAXN], s3[MAXN];
char s[MAXN];

int min (int x, int y) { return x < y ? x : y; }

int main () {
	int Q;
	cin >> Q;
	ch[0] = 'R', ch[1] = 'G', ch[2] = 'B';
	while (Q--) {
		int n, k;
		cin >> n >> k;
		int i, j;
		for (i = 0; i < k; i++)
			s1[i] = ch[i % 3], s2[i] = ch[(i + 1) % 3], s3[i] = ch[(i + 2) % 3];
		cin >> s;
		int ans = 999999999;
		for (i = 0; i + k - 1 < n; i++) {
			int cnt1 = 0, cnt2 = 0, cnt3 = 0;
			for (j = 0; j < k; j++) {
				if (s1[j] != s[i + j]) cnt1++;
				if (s2[j] != s[i + j]) cnt2++;
				if (s3[j] != s[i + j]) cnt3++;
			}
			ans = min(ans, min(cnt1, min(cnt2, cnt3)));
		}
		cout << ans << endl;
	}
	return 0;
}