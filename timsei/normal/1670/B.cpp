#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];
int n, vis[26], tot, fuck[N];
char c[2];

void rmain() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	memset(vis, 0, sizeof(vis));
	scanf("%d", &tot);
	for(int i = 1; i <= tot; ++ i) {
		scanf("%s", c);
		vis[c[0] - 'a'] = 1;
	}
	int lst = 1, ans = 0;
	for(int i = 1; i <= n; ++ i) {
		fuck[i] = vis[s[i] - 'a'];
		if(fuck[i]) {
			ans = max(ans, i - lst);
			lst = i;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}