#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 5;

int fa[N], n, m, q, x, y;
vector <int> who[N];

int getf(int x) {
	return (fa[x] == x) ? x : (fa[x] = getf(fa[x]));
}

main(void) {
	cin >> n >> m >> q;
	for(int i = 1; i <= n + m; ++ i) fa[i] = i;
	for(int i = 1; i <= q; ++ i) {
		scanf("%d%d", &x, &y);
		fa[getf(x)] = getf(y + n);
	}
	int ans = 0;
	for(int i = 1; i <= n + m; ++ i) {
		if(fa[i] == i) ++ ans;
	}
	cout << ans - 1 << endl;
}