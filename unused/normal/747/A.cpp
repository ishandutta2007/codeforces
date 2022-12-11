#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = sqrt(n) + 0.5; i >= 1; i--)
	{
		if (n % i == 0)
		{
			printf("%d %d", i, n / i);
			return 0;
		}
	}
}