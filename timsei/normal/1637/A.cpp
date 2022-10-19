#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, t;

void rmain() {
	scanf("%d", &n);
	bool ok = 1;
	for(int i = 1, lst = -1e9; i <= n; ++ i) {
		scanf("%d", &x);
		if(x < lst) ok = 0;
		lst = x;
	}
	if(!ok) puts("YES");
	else puts("NO");
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}