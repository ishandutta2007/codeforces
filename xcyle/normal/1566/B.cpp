#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100005
using namespace std;
int T;
char s[maxn];
void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int now = 1, cnt1 = 0;
	if(s[1] == '0') cnt1++;
	for (int i = 2; i <= n; i++)
	{
		if(s[i] != s[now]) 
		{
			s[++now] = s[i];
			if(s[now] == '0') cnt1++;
		}
	}
	if(cnt1 == 0) printf("0\n");
	else if(cnt1 == 1) printf("1\n");
	else printf("2\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}