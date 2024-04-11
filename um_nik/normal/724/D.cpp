#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200200;
const int A = 26;
int n, m;
char s[N];
int a[N];
int ans[30];

bool check(int x)
{
	int lst = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) continue;
		if (i - lst > m) return false;
		lst = i;
	}
	if (n - lst > m) return false;
	return true;
}

void solve(int x)
{
	int lst1 = -1, lst2 = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) continue;
		if (a[i] < x)
		{
			if (i - lst1 > m)
				ans[x]++;
			lst1 = i;
			continue;
		}
		if (i - lst1 > m)
		{
			ans[x]++;
			lst1 = lst2;
		}
		lst2 = i;
	}
	if (n - lst1 > m)
		ans[x]++;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d %s", &m, s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = (int)(s[i] - 'a');
	int l = -1, r = A - 1;
	while(r - l > 1)
	{
		int x = (l + r) / 2;
		if (check(x))
			r = x;
		else
			l = x;
	}
	for (int i = 0; i < n; i++)
		if (a[i] < r)
			ans[a[i]]++;
	solve(r);
	for (int i = 0; i < A; i++)
		for (int x = 0; x < ans[i]; x++)
			printf("%c", (char)('a' + i));
	printf("\n");

	return 0;
}