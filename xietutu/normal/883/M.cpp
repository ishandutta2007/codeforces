#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (a == c || b == d) printf("%d\n", 2 * (abs(a - c) + abs(b - d) + 1) + 4);
	else printf("%d\n", 2 * (abs(a - c) + 1 + abs(b - d) + 1));
	return 0;
}