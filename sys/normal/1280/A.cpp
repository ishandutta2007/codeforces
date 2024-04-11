#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3e6 + 5, p = 1e9 + 7;
int T, x, pnt;
string str;
int num[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &x);
		cin >> str;
		int siz = str.size();
		for (int i = 0; i < siz; i++)
			num[i + 1] = str[i] - '0';
		pnt = siz;
		for (int i = 1; i <= x; i++)
		{
			if (pnt < x)
			{
				pnt = ((pnt - i + p) * (long long) num[i] + i) % p;
				for (int j = siz + 1; j <= pnt; j++)
					num[j] = num[j - (siz - i)];
				siz = pnt;
			}
			else siz = ((siz - i + p) * (long long) num[i] + i) % p;
		}
		printf("%d\n", siz);
	}
	return 0;
}