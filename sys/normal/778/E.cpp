#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, len, s[Maxn], buc[Maxn], tmp_ord[Maxn], val[Maxn], ord[Maxn], bel[Maxn], f[Maxn][Maxn];
string str, T[Maxn];
void work(int x, int w)
{
	int cost = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int now = T[ord[i]][1001 - x] - '0';
		if (x > max(len, s[ord[i]]) && !(now + w)) continue;
		if (now + w >= 10) cnt++;
		cost += val[(now + w) % 10];
	}
	f[x][cnt] = max(f[x][cnt], f[x - 1][0] + cost);
	for (int i = 1; i <= n; i++)
	{
		int now = T[ord[n - i + 1]][1001 - x] - '0';
		if (x <= max(len, s[ord[n - i + 1]]) || now + w)
			cost -= val[(now + w) % 10];
		cost += val[(now + w + 1) % 10];
		if (now + w == 9) cnt++;
		f[x][cnt] = max(f[x][cnt], f[x - 1][i] + cost);
	}
}
int main()
{
	string tmp;
	cin >> tmp >> n;
	len = tmp.size();
	for (int j = 1; j <= 1001 - len; j++)
		str += '0';
	str += tmp;
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp, ord[i] = bel[i] = i;
		s[i] = tmp.size();
		for (int j = 1; j <= 1001 - s[i]; j++)
			T[i] += '0';
		T[i] += tmp;
	}
	for (int i = 0; i <= 9; i++)
		cin >> val[i];
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= 1001; i++)
	{
		if (str[1001 - i] == '?')
			for (int j = 0 + (i == len); j <= 9; j++)
				work(i, j);
		else work(i, str[1001 - i] - '0');
		int tmp_n = 0;
		memcpy(tmp_ord, ord, sizeof(int[n + 1]));
		for (int j = 1; j <= n; j++)
			if (max(len, s[tmp_ord[j]]) + 1 >= i) ord[++tmp_n] = tmp_ord[j];
		n = tmp_n;
		memcpy(tmp_ord, ord, sizeof(int[n + 1]));
		for (int j = 0; j <= 9; j++)
			buc[j] = 0;
		for (int j = 1; j <= n; j++)
			buc[T[tmp_ord[j]][1001 - i] - '0']++;
		for (int j = 1; j <= 9; j++)
			buc[j] += buc[j - 1];
		for (int j = n; j >= 1; j--)
			ord[buc[T[tmp_ord[j]][1001 - i] - '0']--] = tmp_ord[j];
		for (int j = 1; j <= n; j++)
			bel[ord[j]] = j;
	}
	printf("%d", f[1001][0]);
	return 0;
}