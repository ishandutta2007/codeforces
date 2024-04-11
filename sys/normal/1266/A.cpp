#include <bits/stdc++.h>
using namespace std;
string str;
int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cin >> str;
		int siz = str.size();
		int tot = 0, tag2 = 0;
		bool tag1 = false;
		for (int i = 0; i < siz; i++)
		{
			tot = (tot + str[i]) % 3;
			if ((str[i] - '0') % 2 == 0) tag2++;
			if (str[i] == '0') tag1 = true;
		}
		if (tag1 && tag2 >= 2 && !tot)
			printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}