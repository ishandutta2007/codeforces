#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 100000;
vector<int>G[MAXN + 5];
void addedge(int a, int b) {
	G[a].push_back(b);
	G[b].push_back(a);
}
int tot[5], cnt[5], col[MAXN + 5];
int n, m, x;
int main() {
	scanf("%d%d", &n, &m), x = 1;
	for(int i=1;i<=m;i++) {
		int a, b; scanf("%d%d", &a, &b);
		addedge(a, b);
	}
	for(int i=0;i<G[x].size();i++)
		col[G[x][i]] = 2;
	for(int i=1;i<=n;i++)
		if( col[i] == 0 )
			col[i] = 1;
		else x = i;
	for(int i=0;i<G[x].size();i++)
		if( col[G[x][i]] == 2 ) col[G[x][i]] = 3;
	for(int i=1;i<=n;i++)
		cnt[col[i]]++;
	if( !cnt[1] || !cnt[2] || !cnt[3] ) {
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		tot[1] = tot[2] = tot[3] = 0;
		for(int j=0;j<G[i].size();j++)
			tot[col[G[i][j]]]++;
		for(int j=1;j<=3;j++) {
			if( col[i] == j ) {
				if( tot[j] != 0 ) {
					puts("-1");
					return 0;
				}
			}
			else {
				if( cnt[j] != tot[j] ) {
					puts("-1");
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ", col[i]);
}