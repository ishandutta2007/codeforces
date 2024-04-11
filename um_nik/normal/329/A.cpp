#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


const int N = 111;
int n;
char s[N];
int a[N], b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i] = b[i] = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < n; j++)
		{
			if (s[j] == 'E') continue;
			a[i] = j;
			b[j] = i;
		}
	}
	bool ok = true;
	for (int i = 0; i < n; i++)
		ok &= a[i] != -1;
	if (ok)
	{
		for (int i = 0; i < n; i++)
			printf("%d %d\n", i + 1, a[i] + 1);
		return 0;
	}
	ok = true;
	for (int i = 0; i < n; i++)
		ok &= b[i] != -1;
	if (ok)
	{
		for (int i = 0; i < n; i++)
			printf("%d %d\n", b[i] + 1, i + 1);
		return 0;
	}
	printf("-1\n");
	return 0;
}