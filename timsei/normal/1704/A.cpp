#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y;

char s[N], t[N];

int main() {
int ttt;
	for(cin >> ttt; ttt --;) {
		scanf("%d%d", &n, &m);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		// [n - m + 2, n] [2, m]
		bool ok = 0;
		for(int i = 1; i <= n - m + 1; ++ i) {
			ok |= (s[i] == t[1]);
		}
		for(int i = 2; i <= m; ++ i) {
			ok &= (t[i] == s[i + n - m]);
		}
		if(ok) puts("YEs");
		else puts("NO");
	}
}