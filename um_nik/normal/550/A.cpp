#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 100100;
int n;
char s[N];
int l1 = N, r1 = -1, l2 = N, r2 = -1;

int main()
{
	scanf(" %s ", s);
	n = strlen(s);
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == 'A')
		{
			if (s[i + 1] == 'B')
			{
				l1 = min(l1, i);
				r1 = max(r1, i);
			}
		}
		else if (s[i] == 'B')
		{
			if (s[i + 1] == 'A')
			{
				l2 = min(l2, i);
				r2 = max(r2, i);
			}
		}
	}
	r1--;
	r2--;
	if (r1 > l2 || r2 > l1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}