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

int cnt[1010] = {};
map <int, bool> mp;
int mabs (int x) {  return x < 0 ? -x : x;}
int main () {
	int T = read();
	while (T--) {
		int n = read(), s = read(), k = read();
		mp.clear(); int i, j;
		for (i = 1; i <= k; i++) {
			j = read(); mp[j] = true;
		}
		for (i = 0; i <= n; i++) {
			if ((s + i <= n && !mp[s + i]) || (s - i >= 1 && !mp[s - i]) ) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}