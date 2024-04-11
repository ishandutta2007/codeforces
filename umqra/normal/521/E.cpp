#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e5 + 10;
int n, m;
vector <int> g[N];
vector <int> locG[N];
int up[N];
int tin[N];
int used[N];
int tme = 0;
int stackCand[N];

int comp[N];
int vertexId[N];
int topSt = 0;
vector <int> cycle, branch;
bool inCycle[N], visited[N];
int findVis[N];

int findCycle(int v, int par)
{
	eprintf("Finding cycle... %d(%d)(par : %d)\n", v, comp[v], par);
	findVis[v] = 1;
	for (int to : locG[v])
	{
		if (to == par)
			continue;
		if (!findVis[to])
		{
			int top = findCycle(to, v);
			if (top == -2)
				return -2;
			if (top != -1)
			{
				cycle.push_back(v);
				return top == v ? -2 : top;
			}
		}
		else if (findVis[to] == 1)
		{
			cycle.push_back(v);
			return to;
		}
	}
	findVis[v] = 2;
	return -1;
}

void findCycle(int v)
{
	findCycle(v, -1);
	for (int x : cycle)
		inCycle[x] = 1;
}

bool findBranch(int v)
{
	eprintf("Finding branch... %d(%d)\n", comp[v], v);
	visited[v] = 1;
	if (inCycle[v])
	{
		branch.push_back(v);
		return true;
	}
	for (int to : locG[v])
	{
		if (visited[to])
			continue;
		if (findBranch(to))
		{
			branch.push_back(v);
			return true;
		}
	}
	return false;
}

bool findBranch()
{
	for (int i = 0; i < (int)cycle.size(); i++)
	{
		int a = cycle[(i + (int)cycle.size() - 1) % (int)cycle.size()];
		int b = cycle[i];
		int c = cycle[(i + 1) % (int)cycle.size()];
		eprintf("[%d] %d [%d]\n", a, b, c);
		for (int to : locG[b])
		{
			if (to == a || to == c)
				continue;
			visited[b] = 1;
			eprintf("Start branching...\n");
			findBranch(to);
			branch.push_back(b);
			for (int x : branch)
				eprintf("%d ", comp[x]);
			eprintf("\n");
			eprintf("End branching...\n");
			return true;
		}
	}
	return false;
}

void printVector(vector <int> vs)
{
	printf("%d ", (int)vs.size());
	for (int v : vs)
		printf("%d ", comp[v] + 1);
	puts("");
}

void printAnswer()
{
	puts("YES");
	printVector(branch);
	auto it = find(cycle.begin(), cycle.end(), branch[0]);
	rotate(cycle.begin(), it, cycle.end());
	auto itEnd = find(cycle.begin(), cycle.end(), branch.back());
	printVector(vector <int>(cycle.begin(), itEnd + 1));
	reverse(cycle.begin() + 1, cycle.end());
	itEnd = find(cycle.begin(), cycle.end(), branch.back());
	printVector(vector <int>(cycle.begin(), itEnd + 1));
}

void init(int sz)
{
	fill(visited, visited + sz, 0);
	fill(findVis, findVis + sz, 0);
	fill(inCycle, inCycle + sz, 0);
	cycle.clear();
	branch.clear();
	for (int i = 0; i < sz; i++)
		locG[i].clear();
}

bool processComponent(int cnt)
{
	int sz = 0;
	while (cnt > 0)
	{
		comp[sz++] = stackCand[--topSt];
		cnt--;
	}
	reverse(comp, comp + sz);
	init(sz);
	eprintf("Comp (%d):\n", sz);
	for (int i = 0; i < sz; i++)
		eprintf("%d ", comp[i]);
	eprintf("\n");
	for (int i = 0; i < sz; i++)
		vertexId[comp[i]] = i;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int to : g[comp[i]])
		{
			if (g[to].size() == 0) 
				continue;
//			eprintf("%d ~ %d\n", comp[i], to);
			int a = vertexId[comp[i]];
			int b = vertexId[to];
			eprintf("%d %d\n", a, b);
			locG[a].push_back(b);
			locG[b].push_back(a);
		}
		g[comp[i]].clear();
	}
	if (sz == 2)
		return false;
	findCycle(0);
	eprintf("Cycle:\n");
	for (int v : cycle)
		eprintf("%d(%d) ", comp[v], v);
	eprintf("\n");
	if (findBranch())
	{
		printAnswer();
		return true;
	}
	return false;
}

int dfs(int v)
{
	eprintf("v : %d\n", v);
	tin[v] = tme++;
	up[v] = tin[v];
	used[v] = 1;
	int sz = 1;
	for (int to : g[v])
	{
		if (!used[to])
		{
			int toSz = dfs(to);
			if (up[to] >= tin[v])
			{
				stackCand[topSt++] = v;
				eprintf("v : %d, to : %d, toSz : %d\n", v, to, toSz);
				if (processComponent(toSz + 1))
					exit(0);
			}
			else
				sz += toSz;
			up[v] = min(up[v], up[to]);
		}
		else
			up[v] = min(up[v], tin[to]);
	}
	stackCand[topSt++] = v;
	return sz;
}

void identComps()
{
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			dfs(i);
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	identComps();
	puts("NO");
	return 0;
}