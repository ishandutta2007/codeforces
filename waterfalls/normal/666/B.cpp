#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
vector<int> adj[3013];
int dist[3013][3013];
vector<pair<int,int> > from[3013], to[3013];

void calc(int s) {
	fill(dist[s],dist[s]+n+1,1e9);
	queue<int> frontier;
	dist[s][s] = 0;
	frontier.push(s);
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		for (int i: adj[x]) {
			if (dist[s][i]>1e8) {
				dist[s][i] = dist[s][x]+1;
				frontier.push(i);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (dist[s][i]>1e8) dist[s][i] = -1e8;
	}
}

void process(int x) {
	from[x] = to[x] = { MP(0,x), MP(0,x), MP(0,x), MP(0,x) };
	for (int i=1;i<=n;i++) {
		int low = 0;
		for (int j=0;j<4;j++) {
			if (from[x][j].A<from[x][low].A) low = j;
		}
		if (from[x][low].A<dist[x][i]) from[x][low] = MP(dist[x][i],i);
		low = 0;
		for (int j=0;j<4;j++) {
			if (to[x][j].A<to[x][low].A) low = j;
		}
		if (to[x][low].A<dist[i][x]) to[x][low] = MP(dist[i][x],i);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
	}
	for (int i=1;i<=n;i++) calc(i);
	for (int i=1;i<=n;i++) process(i);
	int best = 0;
	vector<int> which;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) if (i!=j) {
			for (int a=0;a<4;a++) {
				int one = to[i][a].B;
				if (one==i || one==j) continue;
				for (int b=0;b<4;b++) {
					int two = from[j][b].B;
					if (two==i || two==j || two==one) continue;
					if (dist[one][i]+dist[i][j]+dist[j][two]>best) {
						best = dist[one][i]+dist[i][j]+dist[j][two];
						which = { one,i,j,two };
					}
				}
			}
		}
	}
	for (int i: which) printf("%d ",i);
	printf("\n");

	return 0;
}