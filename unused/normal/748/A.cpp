#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d %c",
		(c - 1) / 2 / b + 1,
		(c - 1) / 2 % b + 1,
		c & 1 ? 'L' : 'R');
}