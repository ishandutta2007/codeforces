#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

int ap[100100], buc[100100];
vector <int> v[100100];

int main () {
	int T = read();
	while (T--) {
		int n = read(), m = read(), i, j;
		for (i = 1; i <= n; i++) buc[i] = ap[i] = 0;
		for (i = 1; i <= m; i++) {
			int k = read();
			for (j = 1; j <= k; j++) {
				int x = read(); ++buc[x]; v[i].push_back(x);
				if (k  == 1) ++ap[x];
			}
		}
		int id = 1;
		for (i = 2; i <= n; i++) if (buc[i] > buc[id]) id = i;
		if (buc[id] > ((m + 1) >> 1)) {
			if (ap[id] > ((m + 1) >> 1)) puts("NO");
			else {
				puts("YES"); int now = ((m + 1) >> 1) - ap[id];
				for (i = 1; i <= m; i++) {
					if (v[i].size() == 1 && v[i][0] == id) {
						cout << id << ' ';
					}
					else {
						bool is = 0;
						for (auto k: v[i]) if (k == id) is = 1;
						if (now && is) { --now; cout << id << ' '; }
						else {
							for (auto k: v[i]) if (k != id) { cout << k << ' '; break; }
						}
					}
				}
				cout << endl;
			}
		}
		else {
			puts("YES");
			for (i = 1; i <= m; i++) cout << v[i][0] << ' ';
			cout << endl;
		}
		for (i = 1; i <= m; i++) v[i].clear();
	}
	return 0;
}