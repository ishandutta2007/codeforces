#include "bits/stdc++.h"
using namespace std;

char dat[30];
char ans[2][30];

int main()
{
	scanf("%s", dat);
	int left, right;
	for (int i = 0; i < 26; i++)
	{
		if (dat[i] == dat[i + 1])
		{
			printf("Impossible");
			return 0;
		}
	}

	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 27; j++)
			if (dat[i] == dat[j]) left = i, right = j;

	int diff = (right - left + 1) / 2;

	int px = 0, py = diff - 1;

	for (int i = 0; i < 27; i++)
	{
		int idx = (i + left) % 27;
		if (idx == right)
		{
			continue;
		}

		ans[px][py] = dat[idx];

		if (px == 0)
		{
			if (py > 0) py--;
			else px = 1;
		}
		else
		{
			if (py < 12) py++;
			else px = 0;
		}
	}

	printf("%s\n%s\n", ans[0], ans[1]);
}