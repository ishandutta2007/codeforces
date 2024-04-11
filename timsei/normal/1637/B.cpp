#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, t;

void rmain() {
	scanf("%d", &n);
	
	int ans = 0;
	
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &x);
		if(!x) ans += i * (n - i + 1);
		ans += i * (n - i + 1);
	}
	cout << ans << endl;
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}