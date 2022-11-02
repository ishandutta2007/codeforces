#include<cstdio>
#include<algorithm>
using namespace std;
char s[1000 + 5]; int n;
void solve() {
	scanf("%d%s", &n, s + 1);
	int ans = n;
	for(int i=1;i<=n;i++)
		if( s[i] == '1' )
			ans = max(ans, max(2*i, 2*(n-i+1)));
	printf("%d\n", ans);
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}