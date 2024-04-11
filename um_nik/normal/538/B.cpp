#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

string s;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> s;
	n = s.length();
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, (int)(s[i] - '0'));
	printf("%d\n", ans);
	while(ans--)
	{
		bool f = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
			{
				if (f)
					printf("0");
			}
			else
			{
				f = true;
				printf("1");
				s[i]--;
			}
		}
		printf(" ");
	}
	printf("\n");

	return 0;
}