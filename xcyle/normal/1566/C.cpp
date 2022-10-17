#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100005
using namespace std;
int T, n;
char s[2][maxn];
int f[maxn], last[2];
void solve()
{
	scanf("%d%s%s", &n, s[0] + 1, s[1] + 1);
	for (int i = 0; i <= n; i++) f[i] = 0;
	last[0] = last[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		last[s[0][i] - '0'] = i;
		last[s[1][i] - '0'] = i;
		f[i] = f[i - 1];
		if(last[0]) f[i] = max(f[i - 1], f[last[0] - 1] + 1);
		if(last[1] && last[0]) f[i] = max(f[i], f[min(last[0], last[1]) - 1] + 2);
	}
	printf("%d\n", f[n]);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}