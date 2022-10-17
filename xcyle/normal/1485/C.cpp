#include <iostream>
#include <cstdio>

using namespace std;
int t, x, y;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &x, &y);
		long long ans = 0;
		for (int i = 1; i * i <= x; i++)
		{
			int top = min(y, x / i - 1), bot = i + 1;
			if(top >= bot) ans += (long long)(top - bot + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}