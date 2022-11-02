#include<cstdio>
#include<algorithm>
using namespace std;
void solve() {
	int a, b, c, d, k;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
	int p = (a + c - 1) / c, q = (b + d - 1) / d;
	if( p + q <= k ) printf("%d %d\n", p, q);
	else puts("-1");
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}