#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		if (n <= 99) printf("%d\n", n % 10);
		else
		{
			int mini = 0x3f3f3f3f;
			while (n) mini = min(mini, n % 10), n /= 10;
			printf("%d\n", mini);
		}
	}
	return 0;
}