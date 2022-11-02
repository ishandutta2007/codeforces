#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;
char s[N];

inline long long c2(long long n) {
	return n * (n + 1) / 2;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	long long cnt[2][2];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		++cnt[i & 1][s[i] - 'a'];
	}
	long long ans0 = c2(cnt[0][0]) + c2(cnt[0][1]) + c2(cnt[1][0]) + c2(cnt[1][1]),
			  ans1 = cnt[0][0] * cnt[1][0] + cnt[0][1] * cnt[1][1];
	cout << ans1 << ' ' << ans0 << endl;
	return 0;
}