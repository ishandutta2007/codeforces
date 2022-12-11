#include <bits/stdc++.h>
using namespace std;

int last = 'a';

int main()
{
	for (;;)
	{
		int ch;
		if (scanf(" %c", &ch) != 1) break;
		if (ch > last)
		{
			printf("NO\n");
			return 0;
		}

		if (ch == last) ++last;
	}
	printf("YES\n");
}