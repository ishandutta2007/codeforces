#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
int T, N, A, B, C, D, i, j, x, y, dis[MN];
vi adj[MN]; pii a[MN], b[MN];

void dfs(int n,int p){
	a[n] = b[n] = {0,0};
	for(auto v : adj[n]){
		if(v==p) continue;
		dfs(v, n);
		pii cur = {a[v].F+1, v};
		if(cur.F>a[n].F) b[n]=a[n], a[n]=cur;
		else if(cur.F>b[n].F) b[n]=cur;
	}
}

void dfs2(int n,int p,int d,int &mx){
	mx = min(mx, max(d, a[n].F));
	for(auto v : adj[n]){
		if(v==p) continue;
		if(v==a[n].S) dfs2(v,n,max(b[n].F,d)+1,mx);
		else dfs2(v,n,max(a[n].F,d)+1,mx);
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);
		for(i=1;i<=N;i++)
			adj[i].clear();
		for(i=1;i<N;i++){
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int rad = 1<<30;
		dfs(1, 0);
		dfs2(1, 0, 0, rad);
		if(D>2*C&&rad>C){
			for(i=1;i<=N;i++) dis[i]=-1;
			queue<pii> q;
			q.push({A,0});
			while(q.size()){
				pii cur=q.front(); q.pop();
				dis[cur.F] = cur.S;
				for(auto v : adj[cur.F]){
					if(dis[v]==-1) q.push({v, cur.S+1});
				}
			}
			if(dis[B]<=C) printf("Alice\n");
			else printf("Bob\n");
		}
		else printf("Alice\n");
	}
	return 0;
}