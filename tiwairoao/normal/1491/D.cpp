#include <bits/stdc++.h>

bool check(int u, int v) {
	int cnt = 0;
	for(int i=0;i<30;i++) {
		cnt += (u >> i) & 1;
		cnt -= (v >> i) & 1;
		if( cnt < 0 ) return false;
	}
	return true;
}

void solve() {
	int u, v; scanf("%d%d", &u, &v);
	if( u <= v && check(u, v) ) puts("yEs");
	else puts("nO");
}

int main() {
	int q; scanf("%d", &q);
	while( q-- ) solve();
}