#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int N = 200;

map <int, int> idByIndex;
map <int, int> indexById;

int getId(int a)
{
	int sz = (int)idByIndex.size();
	if (idByIndex.find(a) == idByIndex.end())
	{
		idByIndex[a] = sz;
		indexById[sz] = a;
	}
	return idByIndex[a];
}

int g[N][N];
vector <int> friends[N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int m, k;
	scanf("%d%d", &m, &k);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ia = getId(a);
		int ib = getId(b);
		g[ia][ib] = g[ib][ia] = 1;
	}

	int n = (int)idByIndex.size();
	for (int i = 0; i < n; i++)
	{
		int all = 0;
		for (int s = 0; s < n; s++)
			if (g[i][s])
				all++;
		for (int s = 0; s < n; s++)
		{
			if (i == s || g[i][s])
				continue;
			int cnt = 0;
			for (int q = 0; q < n; q++)
			{
				if (g[i][q] && g[s][q])
					cnt++;
			}
			if (cnt * 100 >= all * k)
				friends[i].push_back(s);
		}
	}

	for (auto p : idByIndex)
	{
		int id = p.second;
		int real = p.first;
		printf("%d: ", real);

		printf("%d ", (int)friends[id].size());
		vector <int> ids;
		for (int f : friends[id]) 
			ids.push_back(indexById[f]);
		sort(ids.begin(), ids.end());
		for (int f : ids)
			printf("%d ", f);
		puts("");
	}

	return 0;
}