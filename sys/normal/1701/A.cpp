#include <bits/stdc++.h>
using namespace std;

int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int tot = 0;
		for (int i = 1; i <= 4; i++)
		{
			int x;
			scanf("%d", &x);
			tot += x;
		}
		if (tot == 4) puts("2");
		else if (!tot) puts("0");
		else puts("1");
	}
	return 0;
}