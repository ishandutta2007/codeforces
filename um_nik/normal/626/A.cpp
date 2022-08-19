#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s;
int n;
int ans;

int main()
{
	cin >> n >> s;
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		for (int j = i; j < n; j++)
		{
			if (s[j] == 'L')
				x--;
			else if (s[j] == 'R')
				x++;
			else if (s[j] == 'D')
				y--;
			else
				y++;
			if (x == 0 && y == 0) ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}