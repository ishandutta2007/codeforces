#include <iostream>
#include <cstdio>
#define maxn 2005
using namespace std;
int n, k, ans[maxn];
int f[maxn][maxn];
char need[10][8] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char s[maxn][8];
inline int check(int pos, int dig)
{
	int cnt = 0;
	for (int i = 0; i < 7; i++)
	{
		if(s[pos][i] == need[dig][i]) continue;
		if(s[pos][i] == '1') return -1;
		else cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i]);
	}
	f[n + 1][0] = 1;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j <= k; j++)
		{
			for (int d = 0; d <= 9; d++)
			{
				int tmp = check(i, d);
				if(tmp == -1 || j - tmp < 0) continue;
				f[i][j] |= f[i + 1][j - tmp];
			}
		}
	}
	if(!f[1][k])
	{
		printf("-1\n");
		return 0;
	}
	int rest = k;
	for (int i = 1; i <= n; i++)
	{
		for (int d = 9; d >= 0; d--)
		{
			int tmp = check(i, d);
			if(tmp == -1 || rest - tmp < 0) continue;
			if(!f[i + 1][rest - tmp]) continue;
			ans[i] = d;
			rest -= tmp;
			break;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d", ans[i]);
	return 0;
}