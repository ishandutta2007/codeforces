#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q, ans;
bool vis[Maxn];
string str;
int main()
{
	scanf("%d%d", &n, &q);
	cin >> str;
	for (int i = 0; i < n - 2; i++)
		if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') ans++, vis[i] = true;
	while (q--)
	{
		int pos;
		scanf("%d", &pos);
		pos--;
		char ch = getchar();
		while (!isalpha(ch)) ch = getchar();
		str[pos] = ch;
		for (int i = pos - 2; i <= pos; i++)
		{
			ans -= vis[i];
			vis[i] = (i >= 0 && i < n - 2 && str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c');
			ans += vis[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}