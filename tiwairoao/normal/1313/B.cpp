#include <cstdio>
#include <algorithm>
using namespace std;

void solve() {
	int n, x, y; scanf("%d%d%d", &n, &x, &y);
	int mn, mx;
	if( x + y >= n + 1 ) {
		int k = (x + y + 1);
		int p = k - n;
		mn = n - max(n - p + 1, 1) + 1, mx = n;
	}
	else {
		int k = (x + y);
		int p = k - 1;
		mx = p, mn = 1;
	}
	printf("%d %d\n", mn, mx);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}