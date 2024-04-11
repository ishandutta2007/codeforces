#include <bits/stdc++.h>
using namespace std;

int T;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int pos1 = -1, pos2 = -1;
		cin >> str;
		int siz = str.size();
		for (int i = 0; i < siz - 1; i++)
		{
			if (str[i] == '1' && str[i + 1] == '1' && pos1 == -1) pos1 = i;
			if (str[i] == '0' && str[i + 1] == '0') pos2 = i;
		}
		if (pos1 != -1 && pos2 != -1 && pos2 > pos1) puts("No");
		else puts("Yes");
	}
	return 0;
}