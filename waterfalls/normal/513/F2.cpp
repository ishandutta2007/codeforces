#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

int n,m,tot;
char grid[25][25];
vector<pair<int,int> > males;
vector<pair<int,int> > females;
ll dist[500][500];

const int INF = 1e9;
const ll INFLL = 1e18;

char& get(int i) { return grid[i/m][i%m]; }
void floyd() {
	for (int i=0;i<n*m;i++) for (int j=0;j<n*m;j++) dist[i][j] = INFLL;
	for (int i=0;i<n*m;i++) {
		if (get(i)=='#') continue;
		dist[i][i] = 0;
		if (i/m && get(i-m)=='.') dist[i][i-m] = dist[i-m][i] = 1;
		if (i%m && get(i-1)=='.') dist[i][i-1] = dist[i-1][i] = 1;
	}
	for (int k=0;k<n*m;k++) for (int i=0;i<n*m;i++) for (int j=0;j<n*m;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

vector<int> adj[2013];
int res[2013][2013];
const int source = 2011, sink = 2012;
const int male = 0, female = 500, grid1 = 1000, grid2 = 1500;
void conn(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
	res[a][b] = 1;
}
void make(ll K) {
	for (int i=0;i<2013;i++) {
		adj[i].clear();
		for (int j=0;j<2013;j++) res[i][j] = 0;
	}
	for (int i=0;i<tot;i++) conn(source,male+i);
	for (int i=0;i<tot;i++) conn(female+i,sink);
	for (int i=0;i<tot;i++) for (int j=0;j<n*m;j++) if (dist[males[i].A][j]<=K/males[i].B) conn(male+i,grid1+j);
	for (int i=0;i<tot;i++) for (int j=0;j<n*m;j++) if (dist[females[i].A][j]<=K/females[i].B) conn(grid2+j,female+i);
	for (int i=0;i<n*m;i++) conn(grid1+i,grid2+i);
}

int h[2013];
queue<int> frontier;
int visited[2013];
bool level() {
	for (int i=0;i<2013;i++) h[i] = INF;
	h[source] = 0;
	frontier.push(source);
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		for (int i: adj[x]) if (res[x][i] && h[i]==INF) {
			h[i] = h[x]+1;
			frontier.push(i);
		}
	}
	return (h[sink]!=INF);
}
int dfs(int x) {
	if (x==sink) return 1;
	visited[x] = 1;
	int num = 0;
	for (int i: adj[x]) if (!visited[i] && h[i]==h[x]+1 && res[x][i] && dfs(i)) {
		res[x][i]-=1;
		res[i][x]+=1;
		num+=1;
		if (x!=source) return num;
	}
	return num;
}
int maxflow() {
	int flow = 0;
	while (true) {
		if (!level()) break;
		for (int i=0;i<2013;i++) visited[i] = 0;
		flow+=dfs(source);
	}
	return flow;
}

bool check(ll K) {
	make(K);
	return (maxflow()==tot);
}

void read(int num, vector<pair<int,int> >& dest) {
	for (int i=0;i<num;i++) {
		int r,c,t;
		scanf("%d%d%d",&r,&c,&t);
		dest.push_back(MP((r-1)*m+c-1,t));
	}
}

int main() {
	int a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if (abs(a-b)!=1) return printf("-1\n"), 0;
	for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
	int r,c,t;
	scanf("%d%d%d",&r,&c,&t);
	if (a<b) males.push_back(MP((r-1)*m+c-1,t));
	else females.push_back(MP((r-1)*m+c-1,t));
	read(a,males);
	read(b,females);
	tot = max(a,b);
	floyd();
	ll low = -1;
	ll high = INFLL;
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	printf("%lld\n",(high==INFLL) ? -1 : high);

	return 0;
}