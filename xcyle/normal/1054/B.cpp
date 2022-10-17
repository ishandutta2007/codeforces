#include <iostream>
#include <cstdio>
using namespace std;
int n, a;
int main()
{
	scanf("%d", &n);
	int ans = n + 1;
	int mx = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if(a - 1 > mx) ans = min(ans, i);
		mx = max(mx, a);
	}
	if(ans == n + 1) printf("-1");
	else printf("%d", ans);
	return 0;
}