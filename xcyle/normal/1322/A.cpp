#include <iostream>
#include <cstdio>
#define maxn 1000005
using namespace std;
int n;
char s[maxn];
int f[maxn];
int cnt = 0, ans = 0;
int main()
{
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++)
	{
		if(cnt > 0 || cnt + ((s[i] == ')') ? 1 : -1) > 0) ans++;
		if(s[i] == ')') cnt++;
		else cnt--;
	}
	if(cnt != 0)
	{
		printf("-1\n");
		return 0; 
	}
	else printf("%d", ans);
	return 0;
}