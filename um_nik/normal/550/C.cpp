#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s;
int n;

int main()
{
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++)
	{
		int x = (int)(s[i] - '0');
		if (x % 8 == 0)
		{
			printf("YES\n");
			printf("%d\n", x);
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int x = (int)(s[i] - '0') * 10 + (int)(s[j] - '0');
			if (x % 8 == 0)
			{
				printf("YES\n");
				printf("%d\n", x);
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
			{
				int x = (int)(s[i] - '0') * 100 + (int)(s[j] - '0') * 10 + (int)(s[k] - '0');
				if (x % 8 == 0)
				{
					printf("YES\n");
					printf("%d\n", x);
					return 0;
				}
			}
	printf("NO\n");

	return 0;
}