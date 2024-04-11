#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int a, h, w;
	cin >> a >> h >> w;

	if (a > h || a > w)
	{
		printf("-1\n");
		return 0;
	}

	int g = gcd(h + a, w + a);

	int t = (h + a) / g, b = (w + a) / g;
	int k = min((w + a) / a / b, (h + a) / a / t);
	int x = k * b - 1, y = k * t - 1;

	if (x >= 1 && y >= 1)
	{
		printf("%.9f\n", double(w - a * x) / (x + 1));
	}
	else
	{
		printf("-1\n");
	}
}