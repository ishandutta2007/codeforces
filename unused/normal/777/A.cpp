#include <bits/stdc++.h>
using namespace std;
bool z[4];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	z[m] = true;
	n %= 6;
	for (int i = n; i >= 1; i--)
	{
		if (i % 2) swap(z[0], z[1]);
		else swap(z[2], z[1]);
	}

	for (int i = 0; i <= 2; i++) if (z[i]) printf("%d\n", i);
}