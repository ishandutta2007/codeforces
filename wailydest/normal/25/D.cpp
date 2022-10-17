#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

vector<vector<int> > g;
vector<int> comp;
vector<pair<int, int> > toerase;
vector<bool> used;

void dfs(int v, int prev = -1) 
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == -1) continue;
		if (!used[g[v][i]]) dfs(g[v][i], v);
		else if (g[v][i] != prev) {
			toerase.push_back(make_pair(v, g[v][i]));
			g[v][i] = -1;
		}
	}
}

int main() 
{
	int n;
	cin >> n;
	
	g.resize(n);
	used.resize(n, 0);
	
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comp.push_back(i);
			dfs(i);
		}
	}
	
	cout << comp.size() - 1 << '\n';
	
	set<pair<int, int> > out;
	for (int i = 0, j = 1; i < toerase.size(); ++i, ++j) {
		if (!out.count(toerase[i])) {
			cout << toerase[i].first + 1 << ' ' << toerase[i].second + 1 << ' ' << 1 << ' ' << comp[j] + 1 << '\n';
			out.insert(make_pair(toerase[i].second, toerase[i].first));
		}
		else --j;
	}
	
	return 0;
}