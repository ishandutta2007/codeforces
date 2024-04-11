#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
bool adj[413][413];
int dist[413][413][2];
deque<pair<pair<int,int>,int> > frontier;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a][b] = adj[b][a] = 1;
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) for (int k=0;k<2;k++) dist[i][j][k] = 1e9;
	dist[1][1][0] = 0;
	frontier.push_back(MP(MP(1,1),0));
	while (frontier.size()>0) {
		int a = frontier.front().A.A, b = frontier.front().A.B;
		int c = frontier.front().B;
		frontier.pop_front();
		if (c==0) {
			for (int i=1;i<=n;i++) if (a==i || adj[a][i]) {
				if (dist[a][b][c]+1<dist[i][b][1]) {
					dist[i][b][1] = dist[a][b][c]+1;
					frontier.push_back(MP(MP(i,b),1));
				}
			}
		} else {
			for (int i=1;i<=n;i++) if (b==i || !adj[b][i]) {
				if (i==a && i!=n) continue;
				if (dist[a][b][c]<dist[a][i][0]) {
					dist[a][i][0] = dist[a][b][c];
					frontier.push_front(MP(MP(a,i),0));
				}
			}
		}
	}
	int ans = min(dist[n][n][0],dist[n][n][1]);
	if (ans>1e8) printf("-1\n");
	else printf("%d\n",ans);

	return 0;
}