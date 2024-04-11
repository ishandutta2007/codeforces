#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

const int maxnodes = 72;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, 0};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}

const int mxN=1e5;
int lf[6], msks[mxN], mc[64];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	string s;
	cin >> s;
	int n=s.size(), m;
	cin >> m;
	for(char c : s)
		++lf[c-'a'];
	for(int i=0; i<n; ++i)
		msks[i]=63;
	while(m--) {
		int a;
		cin >> a, --a;
		string b;
		cin >> b;
		msks[a]=0;
		for(char c : b)
			msks[a]|=1<<(c-'a');
	}
	for(int i=0; i<n; ++i)
		++mc[msks[i]];
	string ans;
	for(int i=0; i<n; ++i) {
		bool ok=0;
		for(int j=0; j<6&&!ok; ++j) {
			if((msks[i]>>j)%2==0)
				continue;
			--mc[msks[i]];
			++mc[1<<j];
			for(int k=0; k<72; ++k)
				g[k].clear();
			for(int k=0; k<6; ++k)
				addEdge(0, 1+k, lf[k]);
//				g.addEdge(0, 1+k, lf[k]);
			for(int k=0; k<64; ++k) {
				for(int l=0; l<6; ++l)
					if((k>>l)%2==1)
						addEdge(1+l, 7+k, mc[k]);
//						g.addEdge(1+l, 7+k, mc[k]);
				addEdge(7+k, 71, mc[k]);
//				g.addEdge(7+k, 71, mc[k]);
			}
			if(maxFlow(0, 71)==n) {
				ok=1;
				ans+=(char)(j+'a');
			} else {
				++mc[msks[i]];
				--mc[1<<j];
			}
		}
		if(!ok) {
			cout << "Impossible";
			return 0;
		}
	}
	cout << ans;
	/*
    int n = 3;
    nodes = n;

    int capacity[][3] = { { 0, 3, 2 }, { 0, 0, 2 }, { 0, 0, 0 } };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (capacity[i][j] != 0)
                addEdge(i, j, capacity[i][j]);
    cout << (4 == maxFlow(0, 2)) << endl;
    */
}