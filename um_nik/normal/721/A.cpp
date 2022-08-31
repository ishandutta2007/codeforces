#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 1010;
int n;
char s[N];
int ans[N];
int m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d %s", &n, s);
	m = 0;
	int len = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			if (len == -1) continue;
			ans[m++] = len;
			len = -1;
		}
		else
		{
			if (len == -1) len = 0;
			len++;
		}
	}
	if (len > -1)
		ans[m++] = len;
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}