#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n;

map <int, int> Map;

int calc(int x) {
	for(int i = 1; i <= 1000; ++ i) {
		if((1 << i) - 1 >= x) return i;
	}
	return 0;
}

void rmain() {
	scanf("%d", &n);
	Map.clear();
	for(int i = 1, x; i <= n; ++ i) {
		scanf("%d", &x);
		++ Map[x];
	}
	int res = 0;
	for(auto V : Map) res = max(res, V.second);
	if(n == res) {
		puts("0");
		return;
	}
	printf("%d\n", calc((n - res - 1) / res + 1) + n - res);
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}