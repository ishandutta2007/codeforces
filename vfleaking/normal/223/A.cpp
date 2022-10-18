#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	static char s[MaxN + 1];
	
	scanf("%s", s);
	n = strlen(s);
	
	stack<int> sta;
	
	static int f[MaxN];
	
	for (int i = 0; i < n; i++)
	{
		f[i] = -1;
		if (s[i] == ')' && !sta.empty() && s[sta.top()] == '(')
		{
			f[i] = sta.top();
			sta.pop();
		}
		else if (s[i] == ']' && !sta.empty() && s[sta.top()] == '[')
		{
			f[i] = sta.top();
			sta.pop();
		}
		else
			sta.push(i);
	}
	
	for (int i = 0; i < n; i++)
		if (f[i] > 0 && f[f[i] - 1] != -1)
			f[i] = f[f[i] - 1];
	
	static int sum[MaxN + 1];
	sum[0] = 0;
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (s[i] == '[' ? 1 : 0);
	
	int res = 0;
	int l, r;
	for (int i = 0; i < n; i++)
		if (f[i] != -1)
		{
			int t = sum[i + 1] - sum[f[i]];
			if (t > res)
			{
				res = t;
				l = f[i];
				r = i;
			}
		}
	
	cout << res << endl;
	if (res != 0)
	{
		for (int i = l; i <= r; i++)
			putchar(s[i]);
		cout << endl;
	}
	
	return 0;
}