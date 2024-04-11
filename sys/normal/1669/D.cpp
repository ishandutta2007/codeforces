#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool las = false, flag1 = false, flag2 = false;
		scanf("%d", &n);
		cin >> str;
		str += 'W';
		n++;
		for (int i = 0; i < n; i++)
			if (str[i] == 'W')
			{
				if (las && !(flag1 && flag2))
				{
					puts("NO");
					goto END;
				}
				las = flag1 = flag2 = false;
			}
			else
			{
				las = true;
				flag1 |= str[i] == 'B';
				flag2 |= str[i] == 'R';
			}
		puts("YES");
		END:;
	}
	return 0;
}