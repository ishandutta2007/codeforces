#include <bits/stdc++.h>
using namespace std;

char str[100];

int main()
{
	int k;
	scanf("%s%d", str, &k);
	int len = strlen(str);

	int cnt = 0, zero = 0;
	for (int i = len - 1; i >= 1; i--)
	{
		if (str[i] == '0') zero++;
		else cnt++;

		if (zero == k)
		{
			printf("%d\n", cnt);
			return 0;
		}
	}

	printf("%d\n", len - 1);
}