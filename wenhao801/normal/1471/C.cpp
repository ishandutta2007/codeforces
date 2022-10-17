#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 300300;
#define ll long long
int n, m;
int k[MAXN], c[MAXN];
priority_queue < int, vector<int>, greater<int> > pq;

int main () {
	int T = read();
	while (T--) {
		while (!pq.empty()) pq.pop();
		n = read(), m = read();
		int i, j;
		for (i = 1; i <= n; i++) k[i] = read();
		for (i = 1; i <= m; i++) c[i] = read();
		sort(k + 1, k + n + 1); ll ans = 0;
		for (i = 1, j = 0; i <= m; i++) {
			pq.push(c[i]);
			while (j + 1 <= n && k[j + 1] == i) {
				if (pq.top() < c[i]) {
					int tmp = pq.top();
					ans += pq.top(); pq.pop();
					pq.push(c[i]);
				}
				else ans += c[i];
				++j;
			}
		}
		cout << ans << endl;
	}
	return 0;
}