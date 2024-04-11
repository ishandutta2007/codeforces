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

const int MAXN = 100100;
#define ll long long
map <int, ll> s;
int n, a[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) { a[i] = read(); s[a[i]] += (n - i + 1); }
		ll ans = 0;
		for (i = 1; i <= n; i++) {
			s[a[i]] -= (n - i + 1);
			ans += 1ll * i * s[a[i]];
		}
		cout << ans << endl;
		s.clear();
	}
	return 0;
}