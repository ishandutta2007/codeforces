#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = a * 8 + b * 4 + c * 2 + d;

	int e = a | b;
	int f = c ^ d;
	int g = b & c;
	int h = a | d;

	int i = e & f;
	int j = g ^ h;

	if (sum == 12 || sum == 2 || sum == 14 || sum == 8 || sum == 9 || sum == 1 || sum == 4) printf("%d\n", i | j);
	else if (sum == 6 || sum == 10 || sum == 5 || sum == 13 || sum == 15) printf("%d\n", !(i | j));
	else printf("%d\n", (i | j));
}