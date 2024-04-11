#include <bits/stdc++.h>
using namespace std;

bool yes[10][10];

int main()
{
	yes[3][3] = true;
	yes[4][6] = yes[6][4] = true;
	yes[5][9] = yes[9][5] = true;
	yes[7][7] = true;
	yes[8][0] = yes[0][8] = true;

	char str[15];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (yes[str[i] - '0'][str[len - 1 - i] - '0'] == false)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}