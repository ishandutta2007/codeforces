#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)3e6 + 10;
int n;
char s[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d %s ", &n, s);
	int d = 0, r = 0;
	int curD = 0, curR = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'D')
			curD++;
		else
			curR++;
	for (int i = 0; curD > 0 && curR > 0 && i < n; i++)
	{
		if (s[i] == 'D')
		{
			if (r > 0)
			{
				r--;
				curD--;
			}
			else
			{
				d++;
				s[n++] = 'D';
			}
		}
		else
		{
			if (d > 0)
			{
				d--;
				curR--;
			}
			else
			{
				r++;
				s[n++] = 'R';
			}
		}
	}

	if (curD == 0)
		printf("R\n");
	else
		printf("D\n");

	return 0;
}