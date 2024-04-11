#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200;
char s[N][N];
int n;
int ALP = 26;
bool g[N][N];
vector<int> ord;
bool used[N];

void dfs(int v)
{
	used[v] = 1;
	for (int u = 0; u < ALP; u++)
	{
		if (!g[v][u]) continue;
		if (used[u]) continue;
		dfs(u);
	}
	ord.push_back(v);
	return;
}

void getTopSort()
{
	for (int i = 0; i < ALP; i++)
	{
		if (used[i]) continue;
		dfs(i);
	}
	reverse(ord.begin(), ord.end());
	for (int i = 0; i < ALP; i++)
		for (int j = 0; j < i; j++)
		{
			int v = ord[i];
			int u = ord[j];
			if (g[v][u])
			{
				printf("Impossible\n");
				return;
			}
		}
	for (int i = 0; i < ALP; i++)
		printf("%c", 'a' + ord[i]);
	printf("\n");
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %s ", s[i]);
	for (int i = 0; i < n - 1; i++)
	{
		int len1 = strlen(s[i]);
		int len2 = strlen(s[i + 1]);
		bool ok = false;
		for (int j = 0; j < min(len1, len2); j++)
		{
			if (s[i][j] == s[i + 1][j]) continue;
			ok = true;
			int x = (int)(s[i][j] - 'a');
			int y = (int)(s[i + 1][j] - 'a');
			g[x][y] = 1;
			break;
		}
		if (!ok)
		{
			if (len2 <= len1)
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}


	getTopSort();

	return 0;
}