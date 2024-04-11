#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define maxn 2005
using namespace std;
char s[maxn][maxn];
int T, n, fa[maxn];
void solve()
{
	scanf("%d", &n);
	ru(i, 1, n) fa[i] = i, scanf("%s", s[i] + i);
	ru(i, 1, n) rd(j, i - 1, 1) if(s[j][i] == '1' && fa[i] > j)
	{
		printf("%d %d\n", j, i);
		if(fa[fa[i] - 1] > j)
		{
			printf("%d %d\n", j, fa[i] - 1);
			rd(k, fa[fa[i] - 1] - 1, j + 1) if(fa[k] == k) printf("%d %d\n", k, i);
		}
		ru(k, j, i) fa[k] = fa[j];
	}
}
int main() {scanf("%d", &T); while(T--) solve();}