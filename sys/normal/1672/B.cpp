#include <bits/stdc++.h>
using namespace std;

int T;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		cin >> str;
		for (int i = 0; i < (int) str.size(); i++)
		{
			cnt += str[i] == 'A' ? 1 : -1;
			if (cnt < 0)
			{
				puts("NO");
				goto END;
			}
		}
		puts(str[str.size() - 1] == 'B' ? "YES" : "NO");
		END:;
	}
	return 0;
}