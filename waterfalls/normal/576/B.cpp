#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int p[100013];
int visited[100013];
vector<vector<int> > groups;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) if (!visited[i]) {
		vector<int> has(1,i);
		visited[i] = 1;
		int where = p[i];
		while (where!=i) {
			visited[where] = 1;
			has.push_back(where);
			where = p[where];
		}
		if (has.size()==1) {
			printf("YES\n");
			for (int j=1;j<=n;j++) if (j!=i) printf("%d %d\n",i,j);
			return 0;
		}
		groups.push_back(has);
	}
	for (auto g: groups) if (g.size()%2==1) return printf("NO\n"), 0;
	vector<int> g;
	for (auto gg: groups) if (gg.size()==2) g = gg;
	if (g.size()==0) return printf("NO\n"), 0;
	printf("YES\n");
	printf("%d %d\n",g[0],g[1]);
	for (auto gg: groups) if (gg!=g) {
		int prev = g[0];
		for (int x: gg) printf("%d %d\n",prev,x), prev = g[0]^g[1]^prev;
	}

	return 0;
}