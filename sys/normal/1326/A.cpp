#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		if (n == 1)
			puts("-1");
		else
		{
			if (n & 1) printf("22"), n -= 2;
			else printf("2"), n--;
			while (n--) putchar('3');
			puts("");
		}
	}
	return 0;
}