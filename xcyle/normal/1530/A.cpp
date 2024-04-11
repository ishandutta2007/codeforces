#include <iostream>
#include <cstdio>
#define maxn 1005
using namespace std;
int t, x;
void solve()
{
	scanf("%d", &x);
	int ans = 0;
	for (int i = 1; i <= 10; i++) {
	ans = max(ans, x % 10);x /= 10;}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}