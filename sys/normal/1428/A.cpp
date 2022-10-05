#include <bits/stdc++.h>
using namespace std;

int T, a1, b1, a2, b2;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		printf("%d\n", abs(a2 - a1) + abs(b1 - b2) + 2 * (a1 != a2 && b1 != b2));
	}
	return 0;
}