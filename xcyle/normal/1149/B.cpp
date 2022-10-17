#include <iostream>
#include <cstdio>
#define maxn 100005
#define maxl 255
using namespace std;
int n, q, pos;
int nxt[maxn][30];
char S[maxn], t[2];
int f[maxl][maxl][maxl], len[4];
char s[4][maxl];
inline void update(int a1, int a2, int a3)
{
	f[a1][a2][a3] = n + 1;
	if(a1 != 0) f[a1][a2][a3] = min(f[a1][a2][a3], nxt[f[a1 - 1][a2][a3] + 1][s[1][a1] - 'a' + 1]);	
	if(a2 != 0) f[a1][a2][a3] = min(f[a1][a2][a3], nxt[f[a1][a2 - 1][a3] + 1][s[2][a2] - 'a' + 1]);	
	if(a3 != 0) f[a1][a2][a3] = min(f[a1][a2][a3], nxt[f[a1][a2][a3 - 1] + 1][s[3][a3] - 'a' + 1]);
}
int main()
{
	scanf("%d%d%s", &n, &q, S + 1);
	for (int i = 1; i <= 26; i++) nxt[n + 1][i] = n + 1;
	for (int i = 1; i <= 26; i++) nxt[n + 2][i] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= 26; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][S[i] - 'a' + 1] = i;
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%s%d", t, &pos);
		if(t[0] == '-') 
		{
			len[pos]--;
			if(f[len[1]][len[2]][len[3]] != n + 1) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			scanf("%s", t);
			s[pos][++len[pos]] = t[0];
			f[len[1]][len[2]][len[3]] = n + 1;
			if(pos == 1)
			{
				for (int j = 0; j <= len[2]; j++)
				{
					for (int k = 0; k <= len[3]; k++)
					{
						update(len[pos], j, k);
					}
				}
			}
			if(pos == 2)
			{
				for (int j = 0; j <= len[1]; j++)
				{
					for (int k = 0; k <= len[3]; k++)
					{
						update(j, len[pos], k);
					}
				}
			}
			if(pos == 3)
			{
				for (int j = 0; j <= len[1]; j++)
				{
					for (int k = 0; k <= len[2]; k++)
					{
						update(j, k, len[pos]);
					}
				}
			}
			if(f[len[1]][len[2]][len[3]] != n + 1) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}