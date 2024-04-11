#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
inline ll read() {
	ll ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100100;
int n; ll l[MAXN]; char s[MAXN];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) l[i] = read();
	scanf("%s", s + 1);
	ll remain = 0, ans = 0, lenG_times_2 = 0; bool passWater = false;
	for (i = 1; i <= n; i++) {
		if (s[i] == 'G') remain += l[i], lenG_times_2 += l[i] << 1ll, ans += 5ll * l[i];
		if (s[i] == 'W') remain += l[i], passWater = true, ans += 3ll * l[i];
		if (s[i] == 'L') {
			ans += l[i];
			if (remain >= l[i]) remain -= l[i];
			else {
				ans += (l[i] - remain) * (passWater ? 3ll : 5ll);
				remain = 0;
			}
		}
		lenG_times_2 = min(lenG_times_2, remain);
	}
	if (remain) {
		ans -= lenG_times_2 << 1ll; remain -= lenG_times_2;
		ans -= remain;
	}
	printf("%lld\n", ans);
	return 0;
}