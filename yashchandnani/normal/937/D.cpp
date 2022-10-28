#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fil(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n,m,s;
vi g[200009];
bool vis[200009],mrk[100009];
vi ans;
bool dfs(int s,int r){
	vis[s] = true;
	if(sz(g[s])==0){
		if(((s>n?1:0)^r)==1) {
			ans.pb(s);
			return true;
		}
		else return false;
	}
	trav(i,g[s]){
		if(!vis[i]) {
			if(dfs(i,r)) {
				ans.pb(s);
				return true;
			}
		}
	}
	return false;
}
void pr(){
	cout<<"Win\n";
	while(!ans.empty()){
		if(ans.back()>n) {
			cout<<ans.back()-n<<' ';
		}
		else cout<<ans.back()<<' ';
		ans.pop_back();
	}
}
bool win(){
	cin>>s;
	fil(vis);
	if(dfs(s,0)){
		pr();
		return true;
	}
	fil(vis);
	if(dfs(s+n,1)){
		pr();
		return true;
	}
	return false;
}

struct graph {
	  int n;
	    vector<vector<int>> adj, rdj;
		  graph(int n) : n(n), adj(n), rdj(n) { }
		    void add_edge(int src, int dst) {
				    adj[src].push_back(dst);
					    rdj[dst].push_back(src);
						  }

			  vector<vector<int>> strongly_connected_components() { // kosaraju
				      vector<int> ord, visited(n);
					      vector<vector<int> > scc;
						      function<void(int,vector<vector<int>>&, vector<int>&)> dfs 
								        = [&](int u, vector<vector<int>> &adj, vector<int> &out) {
											      visited[u] = true;
												        for (int v: adj[u]) 
															        if (!visited[v]) dfs(v, adj, out);
														      out.push_back(u);
															      };
							      for (int u = 0; u < n; ++u)
									        if (!visited[u]) dfs(u, adj, ord);
								      fill(all(visited), false);
									      for (int i = n-1; i >= 0; --i) 
											        if (!visited[ord[i]]) 
														        scc.push_back({}), dfs(ord[i], rdj, scc.back()); 
										      return scc;
											    }
};
bool dfs2(int v){
	if(mrk[v]) return true;
	vis[v] = true;
	trav(i,g[v]){
		if(i>n) i-=n;
		if(!vis[i]&&dfs2(i)) return true;
	}
	return false;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	graph gx(n);
	rep(i,n) {
		int x;cin>>x;
		rep(j,x){
			int y;cin>>y;
			g[i+1].pb(y+n);
			g[i+1+n].pb(y);
			gx.add_edge(i,y-1);
		}
	}
	if(!win()){
		vector<vector<int>> scc = gx.strongly_connected_components();
		fil(vis);
		trav(v,scc){
			if(sz(v)>1){
				trav(i,v) {
					mrk[i+1] = true;
				}
			}
		}
		if(dfs2(s)){
			cout<<"Draw";
		}
		else cout<<"Lose";
	}
	return 0;
}