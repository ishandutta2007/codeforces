#include <iostream>
#include <vector>
using namespace std;

vector<int> g;
vector<bool> color;
vector<pair<int, int> > comp;
vector<int> comp_size;

inline void minusone(int &val, int mod) 
{
	if (!val) val = mod - 1;
	else --val;
}

void dfs(int v, int prev = -1) 
{
	if (prev != -1 && comp[v].first == comp[prev].first) {
		comp_size.push_back(comp[prev].second - comp[v].second + 1);
		comp[v].second = 0;
		return;
	}
	if (comp[v].first != -1) return;
	comp[v].first = comp_size.size();
	comp[v].second = prev == -1 ? 0 : comp[prev].second + 1;
	dfs(g[v], v);
	comp[v] = comp[g[v]];
	minusone(comp[v].second, comp_size[comp[v].first]);
}

int main() 
{
	int t;
	scanf("%d", &t);
	
	char buf[1000000];
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		g.resize(n * m);
		color.resize(n * m);
		comp.resize(n * m, make_pair(-1, 0));
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < m; ++j) color[i * m + j] = buf[j] - '1';
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < m; ++j) {
				switch (buf[j]) {
					case 'L': 
					g[i * m + j] = i * m + j - 1;
					break;
					case 'R':
					g[i * m + j] = i * m + j + 1;
					break;
					case 'U':
					g[i * m + j] = i * m + j - m;
					break;
					default:
					g[i * m + j] = i * m + j + m;
				}
			}
		}
		for (int i = 0; i < n * m; ++i) if (comp[i].first == -1) dfs(i);
		vector<vector<bool> > used(comp_size.size());
		for (int i = 0; i < comp_size.size(); ++i) used[i].resize(comp_size[i]);
		int amount = 0, black = 0;
		for (int i = 0; i < comp_size.size(); ++i) amount += comp_size[i];
		for (int i = 0; i < n * m; ++i) {
			if (color[i] && !used[comp[i].first][comp[i].second]) {
				++black;
				used[comp[i].first][comp[i].second] = 1;
			}
		}
		printf("%d %d\n", amount, black);
		g.clear();
		color.clear();
		comp.clear();
		comp_size.clear();
	}
	return 0;
}