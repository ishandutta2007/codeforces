#include <bits/stdc++.h>
using namespace std;

int T;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cin >> str;
		int ans = 0, cnt = 0, cnt2 = 0, siz = str.size();
		for (int i = 0; i < siz; i++)
		{
			if (str[i] == 'A') cnt++;
			if (str[i] == 'B')
			{
				if (cnt) ans += 2, cnt--;
				else cnt2++;
			}
		}
		printf("%d\n", siz - ans - cnt2 / 2 * 2);
	}
	return 0;
}