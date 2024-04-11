#include <iostream>
#include <cstdio>

using namespace std;
int t, a, b;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		int ans = 1000000007;
		for (int i = 0; i <= 33; i++)
		{
			if(b == 1) 
			{
				b++;
				continue;
			}
			int tmp = a, res = 0;
			while(tmp)
			{
				tmp /= b;
				res++;
			}
			ans = min(ans, res + i);
			b++;
		}
		printf("%d\n", ans);
	}
	return 0;
}