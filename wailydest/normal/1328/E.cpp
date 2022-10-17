#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int n, lg;
vector<vector<int> > g;
vector<int> depth;
vector<vector<int> > up;
vector<int> tin, tout;

void dfs(int v = 0, int prev = 0) 
{
	static int t = 0;
	tin[v] = t++;
	
	up[v].resize(lg);
	up[v][0] = prev;
	for (int i = 1; i < lg; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
	
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != prev) {
			depth[g[v][i]] = depth[v] + 1;
			dfs(g[v][i], v);
		}
	}
	tout[v] = t++;
}

bool isparent(int parent, int v) 
{
	return tin[parent] <= tin[v] && tout[v] <= tout[parent];
}

int lca(int a, int b) 
{
	if (isparent(a, b)) return a;
	if (isparent(b, a)) return b;
	for (int i = lg - 1; i >= 0; --i) if (!isparent(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

void prep() 
{
	lg = 32 - __builtin_clz(n) - (n == (1 << (31 - __builtin_clz(n))));
	up.resize(n);
	tin.resize(n);
	tout.resize(n);
	depth.resize(n);
	depth[0] = 0;
	dfs();
}


int main()
{
    int t;
    cin >> n >> t;
    
    g.resize(n);
    
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
	
	prep();
    
    vector<int> q;
    int m;
    int max_depth;
    int v = 0;
    bool broken;
    while (t--) {
        max_depth = INT_MIN;
        cin >> m;
        q.resize(m);
        for (int i = 0; i < m; ++i) cin >> q[i];
        for (int i = 0; i < m; ++i) {
            if (max_depth < depth[q[i] - 1]) {
                max_depth = depth[q[i] - 1];
                v = q[i] - 1;
            }
        }
        broken = false;
        for (int i = 0; i < m; ++i) {
            if (depth[q[i] - 1] - depth[lca(v, q[i] - 1)] > 1) {
                cout << "NO";
                broken = true;
                break;
            }
        }
        if (!broken) cout << "YES";
        cout << '\n';
    }
    
    return 0;
}