#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = (int)30000;
int n, M;
int T;
int a[N];
int b[N];
int ans[N];

int parse(string s)
{
	int res = 0;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (i % 3 == 2) continue;
		if (i % 3 == 0)
			res *= 6;
		else
			res *= 10;
		res += (int)(s[i] - '0');
	}
	return res;
}

void read()
{
	cin >> n >> M >> T;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		a[i] = parse(s);
	}
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		while(a[idx] + T <= a[i])
			idx++;
		b[i] = idx;
	}
	return;
}

void solve()
{
	ans[0] = 1;
	for (int i = 1; i < n; i++)
	{
		ans[i] = ans[i - 1];
		if (ans[i] + 1 <= ans[b[i]] + M - 1)
			ans[i]++;
	}
	return;
}

bool checkAns()
{
	for (int i = 0; i < n; i++)
		if (ans[i] - ans[b[i]] == M - 1)
			return true;
	return false;
}

void printAns()
{
	printf("%d\n", ans[n - 1]);
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return;
}

int main()
{
	read();
	solve();
	if (!checkAns())
	{
		printf("No solution\n");
		return 0;
	}
	printAns();

	return 0;
}