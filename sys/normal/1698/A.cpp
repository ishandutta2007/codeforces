#include <bits/stdc++.h>
using namespace std;

int T, n; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (i == 1) printf("%d\n", x);
		}
	}
	return 0;
}