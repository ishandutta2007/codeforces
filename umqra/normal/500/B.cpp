#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int N = 400;
vector <int> g[N];
int a[N];
int p[N];
int used[N];
char table[N][N];
int listV[N];
int listValue[N];
int indV = 0;


void dfs(int v)
{
	used[v] = 1;
	listV[indV++] = v;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		scanf(" %s", table[i]);

	for (int i = 0; i < n; i++)
		for (int s = 0; s < n; s++)
			if (table[i][s] == '1')
				g[i].push_back(s);

	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			indV = 0;
			dfs(i);
			for (int s = 0; s < indV; s++)
				listValue[s] = a[listV[s]];
			sort(listValue, listValue + indV);
			sort(listV, listV + indV);
			for (int s = 0; s < indV; s++)
				p[listV[s]] = listValue[s];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);

	return 0;
}