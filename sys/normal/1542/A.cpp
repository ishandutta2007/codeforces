#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ct = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x & 1) ct++;
		}
		puts(ct == n ? "Yes" : "No");
	}
	return 0;
}