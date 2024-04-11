#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int MaxN = 1000000;

int n;
char s[1 + MaxN + 1];

inline void print(const int &v)
{
	if (v == n + 1)
		return;

	if (s[v] == 'l')
	{
		print(v + 1);
		printf("%d\n", v);
	}
	else
	{
		printf("%d\n", v);
		print(v + 1);
	}
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);

	stack<int> sta;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'l')
			sta.push(i);
		else
			printf("%d\n", i);
	}
	while (!sta.empty())
	{
		printf("%d\n", sta.top());
		sta.pop();
	}

	return 0;
}