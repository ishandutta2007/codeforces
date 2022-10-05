#include <bits/stdc++.h>
using namespace std;

const int Maxn = 150005;
string str;
int ans, T;
bool del[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cin >> str;
		int siz = str.size();
		for (int i = 0; i < siz; i++)
			del[i] = false;
		ans = 0;
		for (int i = 0; i < siz; i++)
			if (i + 2 < siz && str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o' && str[i + 3] != 'o')
				del[i + 2] = true;
			else if (i + 2 < siz && str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o') del[i + 1] = true;
			else if (i + 2 < siz && str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e' && (i == 0 || (i - 1 >= 0 && str[i - 1] != 'o')))
				del[i] = true;
			else if (i + 2 < siz && str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e')
				del[i + 1] = true;
		for (int i = 0; i < siz; i++)
			ans += del[i];
		printf("%d\n", ans);
		for (int i = 0; i < siz; i++)
			if (del[i]) printf("%d ", i + 1);
		printf("\n");
	}
	return 0;
}