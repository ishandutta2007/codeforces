#include <iostream>
#include <cstring>
#include <algorithm>

const int mv = 300, me = 10*(2*201 + 4*101);
const int INF = 100000;

int to[me], ant[me], cap[me], z;
int adj[mv], copy_adj[mv], fila[mv], level[mv];

int a[mv], b[mv];
int ans[mv][mv];

inline void add(int a, int b, int c){
	ant[z] = adj[a], to[z] = b, cap[z] = c, adj[a] = z++;
	std::swap(a, b);
	ant[z] = adj[a], to[z] = b, cap[z] = 0, adj[a] = z++;
}

int bfs(int src, int sink){
	memset(level, -1, sizeof level);
	level[src] = 0;
	int front = 0, size = 0;
	fila[size++] = src;
	while(front < size){
		int v = fila[front++];
		for(int i = adj[v]; i != -1; i = ant[i]){
			if(cap[i] && level[to[i]] == -1){
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int v, int sink, int flow){
	if(v == sink)
		return flow;
	int f;
	for(int &i = copy_adj[v]; i!=-1; i = ant[i]){
		if(cap[i] && level[to[i]] == level[v]+1 && (f = dfs(to[i], sink, std::min(flow, cap[i])))){
			cap[i] -= f, cap[i^1] += f;
			return f;
		}
	}
	return 0;
}

int maxflow(int src, int sink){
	int ret = 0, flow;
	while(bfs(src, sink)){
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(src, sink, 1 << 30)))
		{
			ret += flow;
		}
	}
	return ret;
}

void init()
{
	memset(adj, -1, sizeof adj);
	z = 0;
}

int main()
{
	init();

	int src = mv - 4, sink = mv - 3;
	int n, m;
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
		std::cin >> a[i];
	for(int i=1;i<=n;i++)
		std::cin >> b[i];

	while(m--)
	{
		int u, v;
		std::cin >> u >> v;
		add(u, n + v, INF);
		add(v, n + u, INF);
	}
	int aa, bb;
	aa = bb = 0;
	for(int i=1;i<=n;i++)
	{
		add(src, i, a[i]);
		add(n+i, sink, b[i]);
		add(i, n+i, INF);
		aa += a[i];
		bb += b[i];
	}
	int flow = maxflow(src, sink);
	if(aa != bb || flow != bb)
	{
		std::cout << "NO\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=adj[i];j!=-1;j=ant[j])
		{
			int v=to[j];
			int total_cap = cap[j] + cap[j^1];
			if(v <= 2*n && v > n)
			{
				int used = total_cap - cap[j];
				ans[i][v - n] = used;
			}
		}
	}

	std::cout << "YES\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j!=1)
				std::cout << ' ';
			std::cout << ans[i][j];
		}
		std::cout << '\n';
	}

}