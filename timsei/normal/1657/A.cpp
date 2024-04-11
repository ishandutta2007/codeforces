#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int dp[505][505], n, m, x, y;

#define fi first
#define se second
#define mp make_pair

queue < pair <int, int> > q;

bool ok(int x, int y) {
	return (x >= 0 && x < 505) && (y >= 0 && y < 505);
}

int main() {
	
	int t;
	for(cin >> t; t --;) {
		int x, y;
		cin >> x >> y;
		if(x == 0 && y == 0) {
			puts("0"); continue;
		}
		int z = (int) sqrt(x * x + y * y);
		if(z * z == x * x + y * y) {
			puts("1");
		} else puts("2");
	}
}