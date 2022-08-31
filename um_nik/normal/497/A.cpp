#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int ans;
const int N = 1010;
char s[N][N];
bool u[N];

int main()
{

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s ", &s[i]);
	for (int i = 0; i < m; i++)
	{
		bool bad = false;
		for (int j = 0; j < n - 1; j++)
			bad |= !u[j] && (s[j][i] > s[j + 1][i]);
		if (bad)
			ans++;
		else
		{
			for (int j = 0; j < n - 1; j++)
				u[j] |= s[j][i] < s[j + 1][i];
		}
	}
	printf("%d\n", ans);

	return 0;
}