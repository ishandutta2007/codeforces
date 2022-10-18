#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100000;
const int MaxL = 50;

int main()
{
	int n;
	static char a[MaxN + 1][MaxL + 1];
	static char b[MaxN + 1][MaxL + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%s %s", a[i], b[i]);

	static char last[MaxL + 1];
	for (int k = 1; k <= n; k++)
	{
		int i;
		scanf("%d", &i);

		if (k == 1)
			strcpy(last, strcmp(a[i], b[i]) < 0 ? a[i] : b[i]);
		else
		{
			static char cur[MaxL + 1];
			strcpy(cur, "");
			if (strcmp(last, a[i]) < 0)
				strcpy(cur, a[i]);
			if (strcmp(last, b[i]) < 0)
			{
				if (strlen(cur) == 0 || strcmp(b[i], cur) < 0)
					strcpy(cur, b[i]);
			}
			if (strlen(cur) == 0)
			{
				cout << "NO" << endl;
				return 0;
			}
			strcpy(last, cur);
		}
	}

	cout << "YES" << endl;

	return 0;
}