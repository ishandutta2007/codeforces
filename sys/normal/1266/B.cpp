#include <bits/stdc++.h>
using namespace std;

int T;
long long x;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &x);
		if (x % 7 == 0)
		{
			printf("No\n");
			goto END;
		}
		if (x / 7 < 2)
		{
			printf("No\n");
			goto END;
		}
		if ((x / 7) % 2 != 0)
		{
			printf("No\n");
			goto END;
		}
		printf("Yes\n");
		END:;
	}
	return 0;
}