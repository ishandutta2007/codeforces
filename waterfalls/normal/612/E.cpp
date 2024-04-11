#include <bits/stdc++.h>
using namespace std;

int n;
int p[1000013];
int visited[1000013];
vector<vector<int> > has[1000013];
int ans[1000013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) if (!visited[i]) {
		vector<int> cur(1,i);
		int where = i;
		visited[where] = 1;
		while (p[where]!=i) {
			where = p[where];
			visited[where] = 1;
			cur.push_back(where);
		}
		has[cur.size()].push_back(cur);
	}
	for (int i=1;i<=n;i++) if (i%2==0 && has[i].size()%2==1) return printf("-1\n"), 0;
	for (int i=1;i<=n;i++) {
		if (i%2==1) {
			for (auto v: has[i]) {
				for (int j=0;j<i;j++) {
					ans[v[j]] = v[(j+i/2+1)%i];
				}
			}
		} else {
			for (int k=0;k<has[i].size();k+=2) {
				auto v = has[i][k];
				auto w = has[i][k+1];
				for (int j=0;j<i;j++) {
					ans[v[j]] = w[j];
					ans[w[j]] = v[(j+1)%i];
				}
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}