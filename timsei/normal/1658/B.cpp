#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, x, y, A[N];

void rmain() {
	scanf("%d", &n);
	if(n == 1) {
		puts("0");
		return;
	}
	if(n == 2) {
		puts("1");
		return;
	}
	if(n == 3) {
		puts("0");
		return;
	}
	if(n == 4) {
		puts("4");
		return;
	}
	if(n & 1)  {
		puts("0");
		return;
	}
	int ans = 1;
	for(int i = 1; i <= n / 2; ++ i) {
		ans = 1LL * ans * i * i % 998244353;
	}
	cout << ans << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}