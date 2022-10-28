#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pi;
typedef vector<int> vi;
vector<vi> g,bg;
int mat[109][109];
int dp[109][109][26];
bool topo_sort(vector<vi> &edges, vi& idx, int n) {
		vi indeg(n);
		rep(i,n)
			trav(e, edges[i])
				indeg[e]++;
		queue<int> q; // use priority queue for lexic. smallest ans.
		rep(i,n) if (indeg[i] == 0) q.push(-i);
			int nr = 0;
			while (q.size() > 0) {
				int i = -q.front(); // top() for priority queue
				idx[i] = nr++;
				q.pop();
				trav(e, edges[i])
				{
					if (--indeg[e] == 0) q.push(-e);
				}
			}
		return nr == n;
}
int n;
bool vis[109][109];
void solve(int s,int j){
		if(vis[s][j]) return;	
		rep(k,26){	
			dp[s][j][k]=1;
			trav(l,g[s]){
				if(mat[s][l]<k) continue;
				if(dp[j][l][mat[s][l]]==-1) solve(j,l);
				if(dp[j][l][mat[s][l]]==1) {
					dp[s][j][k]=0;
				}
			}
		}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int m;cin>>n>>m;
	vi temp;
	g.resize(n,temp);
	bg.resize(n,temp);
	rep(i,m){
		int u,v;cin>>u>>v;u--;v--;
		char w;cin>>w;mat[u][v] = w-'a';
		g[u].pb(v);bg[v].pb(u);
	}
	vi s(n);
	topo_sort(g,s,n);
	memset(dp,-1,sizeof(dp));
	rep(i,n){
		 rep(k,26) dp[i][i][k]=1;
	}
	rep(i,n) rep(j,n) solve(i,j);
	rep(i,n){
		rep(j,n){
			if(dp[i][j][0]==0) cout<<'A';
			else cout<<'B';
		}
		cout<<'\n';
	}
	return 0;
}