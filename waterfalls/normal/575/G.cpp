#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int N,M;
const int INF = 1e9;

void bfs(int s, vector<int> adj[], vector<int>& dist) {
	queue<int> frontier;
	for (int i=0;i<N;i++) dist.push_back(INF);
	frontier.push(s);
	dist[s] = 0;
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		for (int i: adj[x]) if (dist[i]==INF) {
			dist[i] = dist[x]+1;
			frontier.push(i);
		}
	}
}

vector<int> adjZ[100013];
vector<int> distZ;
vector<int> adjN[100013];
vector<pair<int,int> > adj[100013];
vector<pair<int,int> > adj2[100013];
vector<int> dist;
vector<int> has[100013];
int good[100013];
int from[100013];
int zeros[100013];
vector<int> frontier;
vector<int> shortest;

void backbfs() {
	for (int i=0;i<N;i++) {
		for (auto j: adj[i]) {
			if (dist[j.A]==dist[i]-1) adj2[i].push_back(j);
		}
		swap(adj[i],adj2[i]);
	}
	for (int i=0;i<N;i++) if (dist[i]<INF) has[dist[i]].push_back(i);
	int least = INF;
	for (int i=0;i<N;i++) if (distZ[i]!=INF) least = min(least,dist[i]);
	for (int i=0;i<N;i++) if (distZ[i]!=INF && dist[i]==least) {
		frontier.push_back(i);
		zeros[i] = distZ[i];
	}
	for (int t=least-1;t>=0;t--) {
		int best = 11;
		for (int i: frontier) for (auto j: adj[i]) best = min(best,j.B);
		shortest.push_back(best);
		for (int i: frontier) for (auto j: adj[i]) {
			if (j.B==best) {
				if (!good[j.A] || zeros[j.A]>zeros[i]) {
					from[j.A] = i;
					zeros[j.A] = zeros[i];
				}
				good[j.A] = 1;
			}
		}
		frontier.clear();
		for (int i: has[t]) if (good[i]) frontier.push_back(i);
	}
}

void output() {
	for (int i: shortest) printf("%d",i);
	if (shortest.size()==0) printf("0");
	printf("\n");
	printf("%d\n",shortest.size()+zeros[0]+1);
	int where = 0;
	while (dist[from[where]]==dist[where]+1) {
		printf("%d ",where);
		where = from[where];
	}
	while (where!=N-1) {
		printf("%d ",where);
		for (int i: adjZ[where]) if (distZ[i]+1==distZ[where]) where = i;
	}
	printf("%d\n",N-1);
}

int main() {
	scanf("%d%d",&N,&M);
	for (int i=0;i<M;i++) {
		int a,b,len;
		scanf("%d%d%d",&a,&b,&len);
		if (len==0) {
			adjZ[a].push_back(b);
			adjZ[b].push_back(a);
		}
		adjN[a].push_back(b);
		adjN[b].push_back(a);
		adj[a].push_back(MP(b,len));
		adj[b].push_back(MP(a,len));
	}
	bfs(N-1,adjZ,distZ);
	bfs(0,adjN,dist);
	backbfs();
	output();

	return 0;
}