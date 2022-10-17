#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;
vector<int> g[200000];
bool iswhite[200000];
int res[200000];
int root_answer[200000];

void prep_dfs(int v, int prev);
void res_dfs(int v, int prev);

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	bool val;
	for (int i = 0; i < n; ++i) cin >> iswhite[i];
	
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	
	prep_dfs(0, -1);
	res[0] = root_answer[0];
	
	for (int i = 0; i < g[0].size(); ++i) res_dfs(g[0][i], 0);
	
	for (int i = 0; i < n; ++i) cout << res[i] << ' ';
	cout << '\n';
	
	return 0;
}

void prep_dfs(int v, int prev) 
{
	for (int i = 0; i < g[v].size(); ++i) if (g[v][i] != prev) prep_dfs(g[v][i], v);
	root_answer[v] = 2 * iswhite[v] - 1;
	for (int i = 0; i < g[v].size(); ++i) if (g[v][i] != prev) if (root_answer[g[v][i]] > 0) root_answer[v] += root_answer[g[v][i]];
}
void res_dfs(int v, int prev) 
{
	res[v] = root_answer[v] + max(res[prev] - max(root_answer[v], 0), 0);
	
	for (int i = 0; i < g[v].size(); ++i) if (g[v][i] != prev) res_dfs(g[v][i], v);
}