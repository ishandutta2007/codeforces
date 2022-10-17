#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
}
inline char inputchar()
{
	using namespace Input;
	if(head == tail)
		*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
	return *head++;
}
inline void inputnum(int &ret)
{
	char ch = inputchar();
	while(ch < '0' || ch > '9')
		ch = inputchar();
	ret = ch - '0';
	ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
}
const int MAXN = 1515;
int n, q;
char s[MAXN];
int ans[30][MAXN];
int main()
{
	scanf("%d%s", &n, s + 1);
	memset(ans, 0, sizeof(ans));
	for(char ch = 'a'; ch <= 'z'; ch++)
	{
		for(int i = 1; i <= n; i++)
		{
			int now = 0;
			for(int j = i; j <= n; j++)
			{
				now += (s[j] != ch);
				ans[ch - 'a'][now] = max(ans[ch - 'a'][now], j - i + 1);
			}
		}
		for(int i = 1; i <= n; i++)
			ans[ch - 'a'][i] = max(ans[ch - 'a'][i], ans[ch - 'a'][i - 1]);
	}
	inputnum(q);
	int m;
	char ch;
	for(int i = 1; i <= q; i++)
	{
		inputnum(m);
		ch = inputchar();
		while(ch < 'a' || ch > 'z')
			ch = inputchar();
		printf("%d\n", ans[ch - 'a'][m]);
	}
	return 0;
}