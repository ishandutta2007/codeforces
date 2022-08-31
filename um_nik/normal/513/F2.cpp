#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int INF2 = (int)1e6;
const ll INF = (ll)1e13;
const int TA = 24;
const int N = TA * TA;
const int V = 4 * N + 20;
const int E = 6 * N * N + 10;
char str[TA];
bool table[TA][TA];
int n, m, w, h;
ll distances[2][N][TA][TA];
const int DX[4] = {0, -1, 0, 1};
const int DY[4] = {-1, 0, 1, 0};

int S, T;

struct Edge
{
	int v, to;
	int cap, flow;

	Edge() : v(), to(), cap(), flow() {}
	Edge(int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap), flow(0) {}
};

int edSz;
Edge ed[E];
vector<int> g[V];

struct Item
{
	int x, y;
	ll vel;

	Item() : x(), y(), vel() {}

	void scan()
	{
		scanf("%d%d%I64d", &x, &y, &vel);
		x--;
		y--;
	}
};

vector<Item> a[2];

void read()
{
	scanf("%d%d%d%d", &w, &h, &n, &m);
	if (abs(n - m) != 1)
	{
		printf("-1\n");
		exit(0);
	}
	for (int i = 0; i < w; i++)
	{
		scanf(" %s ", str);
		for (int j = 0; j < h; j++)
			table[i][j] = str[j] == '.';
	}
	Item tmp;
	tmp.scan();
	if (n < m)
		a[0].push_back(tmp);
	else
		a[1].push_back(tmp);
	for (int i = 0; i < n; i++)
	{
		tmp.scan();
		a[0].push_back(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		tmp.scan();
		a[1].push_back(tmp);
	}
	n = (int)a[0].size();
	m = 2 * n + 2 * w * h;
	S = m;
	T = m + 1;
	m += 2;
	return;
}

bool checkCoords(int x, int y)
{
	if (!(x >= 0 && x < w && y >= 0 && y < h))
		return false;
	return table[x][y];
}

ll tmpDist[TA][TA];
int qSz = 0;
int qu[N][2];
void precalcDistForOne(Item per)
{
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++)
			tmpDist[x][y] = INF;
	tmpDist[per.x][per.y] = 0;
	qSz = 1;
	qu[0][0] = per.x;
	qu[0][1] = per.y;
	for (int k = 0; k < qSz; k++)
	{
		int x = qu[k][0], y = qu[k][1];
		ll w = tmpDist[x][y] + 1;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + DX[dir], ny = y + DY[dir];
			if (!checkCoords(nx, ny)) continue;
			if (tmpDist[nx][ny] <= w) continue;
			tmpDist[nx][ny] = w;
			qu[qSz][0] = nx;
			qu[qSz][1] = ny;
			qSz++;
		}
	}
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++)
			if (tmpDist[x][y] != INF)
				tmpDist[x][y] *= per.vel;
	return;
}

void precalcDist()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
		{
	//		printf("---------------\n");
	//		printf("%d %d\n", i, j);
			precalcDistForOne(a[i][j]);
			for (int x = 0; x < w; x++)
			{
				for (int y = 0; y < h; y++)
				{
					distances[i][j][x][y] = tmpDist[x][y];
	//				printf("%d ", distances[i][j][x][y]);
				}
	//			printf("\n");
			}
		}
	return;
}

void clearGraph()
{
	edSz = 0;
	for (int i = 0; i < m; i++)
		g[i].clear();
	return;
}

void addEdge(int v, int to, int cap)
{
	g[v].push_back(edSz);
	ed[edSz++] = Edge(v, to, cap);
	g[to].push_back(edSz);
	ed[edSz++] = Edge(to, v, 0);
	return;
}

void buildGraph(ll val)
{
	clearGraph();
	for (int i = 0; i < n; i++)
	{
		addEdge(S, i, 1);
		addEdge(n + i, T, 1);
	}
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++)
		{
			int v = 2 * n + x * h + y;
			addEdge(v, v + w * h, 1);
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
		{
			int v = i * n + j;
			for (int x = 0; x < w; x++)
				for (int y = 0; y < h; y++)
				{
					if (distances[i][j][x][y] > val) continue;
					int to = 2 * n + x * h + y;
					if (i == 0)
						addEdge(v, to, 1);
					else
						addEdge(to + w * h, v, 1);
				}
		}
	return;
}

int dist[V];
int q[V];
int qS;

bool bfs()
{
	for (int i = 0; i < m; i++)
		dist[i] = INF2;
	dist[S] = 0;
	qS = 1;
	q[0] = S;
	for (int k = 0; k < qS; k++)
	{
		int v = q[k];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			Edge e = ed[g[v][i]];
			if (e.cap == e.flow) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1) continue;
			dist[to] = dist[v] + 1;
			q[qS++] = to;
		}
	}
	return dist[T] != INF2;
}

int idx[V];
int dfs(int v, int pushFlow)
{
	if (v == T || pushFlow == 0) return pushFlow;
	int res = 0;
	for (; idx[v] < (int)g[v].size(); idx[v]++)
	{
		int id = g[v][idx[v]];
		Edge e = ed[id];
		if (e.cap == e.flow) continue;
		int to = e.to;
		if (dist[to] != dist[v] + 1) continue;
		int dF = dfs(to, min(pushFlow, e.cap - e.flow));
		pushFlow -= dF;
		res += dF;
		ed[id].flow += dF;
		ed[id ^ 1].flow -= dF;
		if (pushFlow == 0)
			return res;
	}
	return res;
}

int getFlow()
{
	int res = 0;
	while( bfs() )
	{
		for (int i = 0; i < m; i++)
			idx[i] = 0;
		res += dfs(S, INF2);
	}
	return res;
}

bool solve2(ll val)
{
	buildGraph(val);
	return (getFlow() == n);
}

void solve()
{
	ll L = -1;
	ll R = INF;
	while(R - L > 1)
	{
		ll val = (L + R) / 2;
		if (solve2(val))
			R = val;
		else
			L = val;
	}
	if (R == INF)
		printf("-1\n");
	else
		printf("%I64d\n", R);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	precalcDist();
	solve();

	return 0;
}