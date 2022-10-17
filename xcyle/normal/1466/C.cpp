#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;
const int INF = 20000000;
int T;
char s[maxn];
int f[maxn][2][2];
void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if(n == 1)
	{
		printf("0\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i][0][0] = f[i][0][1] = f[i][1][0] = f[i][1][1] = INF;
	}
	f[2][0][0] = 0;
	f[2][0][1] = f[2][1][0] = 1; 
	f[2][1][1] = 2; 
	if(s[1] == s[2]) f[2][0][0] = INF;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			for (int l1 = 0; l1 <= 1; l1++)
			{
				for (int l2 = 0; l2 <= 1; l2++)
				{
					if(j == 0 && l2 == 0 && s[i] == s[i - 2]) continue;
					if(j == 0 && l1 == 0 && s[i] == s[i - 1]) continue;
					f[i][l1][j] = min(f[i][l1][j], f[i - 1][l2][l1] + j);
				}
			} 
		}
	}
	printf("%d\n", min(min(f[n][0][0], f[n][0][1]), min(f[n][1][0], f[n][1][1])));
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}