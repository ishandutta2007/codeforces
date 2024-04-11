#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int n, m, x, y, k, A[N];

map <int, int> Map;

void rmain() {
	long long n;
	cin >> n;
	if(n < 3) {
		puts("-1");
		return;
	}
	if(n & 1) {
		puts("2");
		return;
	}
	
	int tot = 0, m = n;
	
	while(m % 2 == 0) {
		++ tot; m /= 2;
	}
	if(m == 1) {
		puts("-1");
		return;
	}
	if((__int128)m * (m + 1) / 2 <= (__int128)n) {
		printf("%lld\n", m);
		return;
	} else {
		printf("%lld\n", (1ll << (tot + 1)));
		return;
	}
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}