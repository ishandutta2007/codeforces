#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N, M;
char str[210][210];
int px[] = {1,0,-1,0};
int py[] = {0,1,0,-1};

// Bi-matching source : https://github.com/koosaga/DeobureoMinkyuParty
const int MAXN = 40005, MAXM = 40005;
vector<int> gph[MAXN];
int dis[MAXN], l[MAXN], r[MAXM], vis[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
void add_edge(int l, int r){ gph[l].push_back(r); }
bool bfs(int n){
	queue<int> que;
	bool ok = 0;
	memset(dis, 0, sizeof(dis));
	for(int i=0; i<n; i++){
		if(l[i] == -1 && !dis[i]){
			que.push(i);
			dis[i] = 1;
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto &i : gph[x]){
			if(r[i] == -1) ok = 1;
			else if(!dis[r[i]]){
				dis[r[i]] = dis[x] + 1;
				que.push(r[i]);
			}
		}
	}
	return ok;
}
bool dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(r[i] == -1 || (!vis[r[i]] && dis[r[i]] == dis[x] + 1 && dfs(r[i]))){
			l[x] = i; r[i] = x;
			return 1;
		}
	}
	return 0;
}
int match(int n){
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	int ret = 0;
	while(bfs(n)){
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) if(l[i] == -1 && dfs(i)) ret++;
	}
	return ret;
}

bool ok(int x, int y) {
	return x>=0&&x<N&&y>=0&&y<M;
}
int idx[210][210][4];

int main() {
	scanf("%d%d",&N,&M);
	for (int i=0;i<N;i++) {
		scanf(" %s",str[i]);
//		for (int j=0;j<M;j++) str[i][j] = '#';
	}
	int p = 0, q = 0;
	memset(idx,-1,sizeof(idx));
	int ans = 0;
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			if (str[i][j]=='#') ans++;
			else continue;
			for (int d=0;d<4;d++) {
				int ni = i+px[d], nj = j+py[d];
				if (ok(ni,nj) && str[ni][nj]=='#') {
					if (d==0) {
						idx[i][j][d] = p++;
					}
					else if (d==1) {
						idx[i][j][d] = q++;
					}
					else {
						idx[i][j][d] = idx[ni][nj][d^2];
					}
				}
			}
		}
	}
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			if (idx[i][j][0]!=-1) {
				if (idx[i][j][1]!=-1) add_edge(idx[i][j][0],idx[i][j][1]);
				if (idx[i][j][3]!=-1) add_edge(idx[i][j][0],idx[i][j][3]);
			}
			if (idx[i][j][2]!=-1) {
				if (idx[i][j][1]!=-1) add_edge(idx[i][j][2],idx[i][j][1]);
				if (idx[i][j][3]!=-1) add_edge(idx[i][j][2],idx[i][j][3]);
			}
		}
	}
	printf("%d\n",ans-(p+q-match(p)));

	return 0;
}