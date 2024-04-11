#include <cstdio>
#include <algorithm>
using namespace std;

void solve() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	int ans = 0;
	if( a ) ans++, a--;
	if( b ) ans++, b--;
	if( c ) ans++, c--;
	if( min(a, min(b, c)) == 0 ) {
		if( (a && b) || (b && c) || (c && a) )
			ans++;
	}
	else if( min(a, min(b, c)) == 1 ) {
		if( (a > 1 || b > 1 || c > 1) ) {
			a--, b--, c--;
			ans += 2;
			if( a >= 1 ) a--;
			else if( b >= 1 ) b--;
			else if( c >= 1 ) c--;
		}
		else ans++, a--, b--;
	}
	else {
		a -= 2, b -= 2, c -= 2, ans += 3;
	}
	if( a && b && c ) ans++;
	
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}