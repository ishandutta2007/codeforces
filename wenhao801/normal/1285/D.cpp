#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n;
int a[100100] = {};
int f[33][100100] = {};

int sea (int l, int r, int rua) { int j = rua;
	//printf("sea(%lld %lld %lld)\n", l, r, rua);
	int ori = f[j][l];
	int ans = r;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f[j][mid] > ori) ans = mid, r = mid - 1;
		else l = mid + 1;
		//cout << l << ' ' << r << endl;
	}
	return ans;
}

signed main () {
	n = read();
	int i, j;
	for (i = 1; i <= n; i++) a[i] =read(); sort(a + 1, a + n + 1);
	for (i = 31; i >= 0; i--) {
		int s = 0;
		for (j = 1; j <= n; j++) f[i][j] = (a[j] >> i) & 1ll;
		for (j = 1; j <= n; j++) f[i][j] += f[i][j - 1];
	}
	//for (i = 3; i >= 0; i--) {for (j = 1; j <= n; j++) cout << f[i][j] << ' '; cout << endl;}
	//cout << "!!! " << sea(1, 4, 2) << endl;
	int ans = 123467548647;
	for (i = 1; i <= n; i++) {
		int rua = 0;
		int l = 1, r = n;
		for (j = 31; j >= 0; j--) {
			if (f[j][r] - f[j][l - 1] == 0) continue;
			if (f[j][r] - f[j][l - 1] == r - l + 1) continue;
			rua += 1ll << j;
			if ((a[i] >> j) & 1ll) l = sea(l, r, j);
			else r = sea(l, r, j) - 1;
			//cout << l << ' ' << r << ' ' << j << ' ' << i <<  endl;
		}
		ans = min(ans, rua);
	}
	cout << ans << endl;
	return 0;
}