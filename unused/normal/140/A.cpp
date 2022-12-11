#include <bits/stdc++.h>
using namespace std;

vector<int> num;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (b < c) printf("NO\n");
	else if (b < 2 * c)
	{
		if (a <= 1) printf("YES\n");
		else printf("NO\n");
	}
	else if (b == 2 * c)
	{
		if (a <= 2) printf("YES\n");
		else printf("NO\n");
	}
	else
	{
		double theta = asin((double)c / (b - c)) * 2;
		if (theta * a <= 3.14159265358979323846 * 2 + 1e-9) printf("YES\n");
		else printf("NO\n");
	}
}