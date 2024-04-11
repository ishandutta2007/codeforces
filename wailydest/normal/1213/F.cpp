#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > g, t;
vector<int> out;
vector<bool> visited;
vector<int> comp;

void dfs1(int v) 
{
	visited[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) if (!visited[g[v][i]]) dfs1(g[v][i]);
	out.push_back(v);
}
void dfs2(int v) 
{
	visited[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < t[v].size(); ++i) if (!visited[t[v][i]]) dfs2(t[v][i]);
}

int main() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	g.resize(n);
	t.resize(n);
	visited.assign(n, 0);
	for (int i = 0; i < 2; ++i) {
		int prev, val;
		scanf("%d", &prev);
		for (int i = 1; i < n; ++i) {
			scanf("%d", &val);
			g[prev - 1].push_back(val - 1);
			t[val - 1].push_back(prev - 1);
			prev = val;
		}
	}
	for (int i = 0; i < n; ++i) if (!visited[i]) dfs1(i);
	visited.assign(n, 0);
	string s;
	s.resize(n);
	int letter = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (!visited[out[i]]) {
			dfs2(out[i]);
			for (int i = 0; i < comp.size(); ++i) {
				s[comp[i]] = 'a' + (char)min(letter, 25);
			}
			++letter;
			comp.clear();
		}
	}
	if (letter < k) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		printf("%s\n", s.c_str());
	}
	return 0;
}