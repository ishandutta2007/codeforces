#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <cassert>
#include <ctime>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const double PI = 3.1415926535897932384626433;
const int P = (int) 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double eps = 1e-8;
void debugOutput();

struct Node
{
	vector<int> edges;
	char sym;
	bool used;
	Node() : used(false), sym() {}
};

const int N = 5e2 + 10;
int n, m, cnt[256];
Node mas[N];

void dfs(int v, char s)
{
	if (mas[v].used)
		return;
	mas[v].used = true;
	mas[v].sym = s;
	++cnt[s];
	for (auto e : mas[v].edges)
		dfs(e, s);
}


void solve()
{
	cin >> n >> m;
	for (int i(0); i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		mas[a].edges.push_back(b);
		mas[b].edges.push_back(a);
	}
	int done(0);
	for (int i(0); i < n; ++i)
		if (mas[i].edges.size() == n - 1)
		{
			mas[i].sym = 'b';
			mas[i].used = true;
		}
	for (int i(0); i < n; ++i)
	if (mas[i].used)
		continue;
	else if (done == 0)
	{
		dfs(i, 'a');
		done = 1;
	}
	else if (done == 1)
	{
		dfs(i, 'c');
		done = 2;
	}
	else
	{
		cout << "No";
		return;
	}
	for (int i(0); i < n; ++i)
	{
		if (mas[i].sym == 'b')
			continue;
		int tmp = 0;
		for (auto e : mas[i].edges)
			tmp += mas[e].sym == mas[i].sym;
		if (tmp + 1 != cnt[mas[i].sym])
		{
			cout << "No";
			return;
		}
	}

	cout << "Yes\n";
	for (int i(0); i < n; ++i)
		cout << mas[i].sym;
}



int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("teleports.in", "r", stdin);
	//freopen("teleports.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}