#include <iostream>
#include <cstdio>
using namespace std;
int T;
long long x, y;
void solve()
{
	scanf("%lld%lld", &x, &y);
	if(x + y < 0) printf("-1\n");
	else if((max(x, y) - min(x, y)) & 1) printf("-1\n");
	else if(x == y)
	{
		if(x == 0) printf("0\n");
		else printf("1\n");
	}
	else printf("2\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}