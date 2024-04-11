#include <iostream>
#include <cstdio>
using namespace std;
int T, n, s;
void solve()
{
	scanf("%d%d", &n, &s);
	printf("%d\n", s / ((n / 2) + 1));
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}