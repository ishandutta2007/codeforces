#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n; 
char g[1000][1005];

void addedge(int u, int v) {
	g[u][v] = g[v][u] = 'Y';
}

int main() {
	int k;
	scanf("%d", &k);
	int log = 0;
	while (k >= (1 << log)) {
		++log;
	}
	--log;
	int tag = 2;
	vector<vector<int> > path;
	vector<int> source, target;
	source.push_back(0);
	target.push_back(1);
	path.push_back(source);
	for (int j = 0; j < log; ++j) {
		vector<int> tmp;
		tmp.push_back(tag++);
		tmp.push_back(tag++);
		path.push_back(tmp);
	}
	path.push_back(target);
	for (int j = 0; j < (int)path.size() - 1; ++j) {
		for (int u = 0; u < (int)path[j].size(); ++u) {
			for (int v = 0; v < (int)path[j + 1].size(); ++v) {
				addedge(path[j][u], path[j + 1][v]);
			}
		}
		if ((j < (int)path.size() - 2) && ((k >> j) & 1)) { 
			int cur = tag++;
			for (int u = 0; u < (int)path[j].size(); ++u) {
				addedge(path[j][u], cur);
			}
			for (int u = j + 1; u < (int)path.size() - 2; ++u) {
				addedge(cur, tag);
				cur = tag++;
			}
			addedge(cur, 1);
		}
	}
	printf("%d\n", tag);
	for (int i = 0; i < tag; ++i) {
		for (int j = 0; j < tag; ++j) {
			if (g[i][j] != 'Y') {
				g[i][j] = 'N';
			}
		}
		g[i][tag] = '\0';
		puts(g[i]);
	}
	return 0;
}