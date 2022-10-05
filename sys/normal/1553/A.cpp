#include <bits/stdc++.h>
using namespace std;

int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", n / 10 + (n % 10 == 9));
	}
	return 0;
}