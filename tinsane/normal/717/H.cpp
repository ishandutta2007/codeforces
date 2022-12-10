#pragma region Kek
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<ctime>
#include<cstring>
using namespace std;

#pragma comment(linker, "/STACK:17100500")

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 0
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#pragma endregion

const int N = 50500;
const int T = 1100500;
vector<int> g[N];
vector<int> t[N];
int c[T], ct[N];

int findTeam(int i, int cc)
{
	for (int tt : t[i])
		if (c[tt] == cc)
			return tt;
	return -1;
}

void solve()
{
	int n, m, mxt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++)
		{
			int x;
			scanf("%d", &x);
			mxt = max(mxt, x);
			t[i].push_back(x);
		}
	}

	while (true)
	{
		for (int i = 1; i <= mxt; i++)
			c[i] = rand() % 2;

		bool ok = true;
		for (int i = 0; i < n && ok; i++)
		{	
			ok &= findTeam(i, 0) != -1;
			ok &= findTeam(i, 1) != -1;
		}

		if (ok)
			break;
	}

	for (int i = 0; i < n; i++)
	{
		int bads[2] = { 0, 0 };
		for (int to : g[i])
		{
			if (to < i)
				bads[ct[to]]++;
		}

		if (bads[0] > bads[1])
			ct[i] = 1;
		else
			ct[i] = 0;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", findTeam(i, ct[i]));
	printf("\n");
	for (int i = 1; i <= mxt; i++)
		printf("%d ", c[i] + 1);
	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#endif

	//3 2 2 1
    //2 2 1 1 1 2 2 1 2 1 2 1 2 1 1 1 1 1 2

	srand(31414);
	solve();

	eprintf("\n\nTime: %.3f\n", clock() * 1. / CLOCKS_PER_SEC);
}