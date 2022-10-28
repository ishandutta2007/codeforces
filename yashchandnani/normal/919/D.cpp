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
typedef vector<int> vi;
vector<set<int> > g,bg;
vector<vector<pii> > gg;
vi idx;
string s;
bool topo_sort(vector<set<int> > &edges, vi &idx, int n) {
		vi indeg(n);
		rep(i,n)
			trav(e, edges[i])
				indeg[e]++;
		queue<int> q; // use priority queue for lexic. smallest ans.
		rep(i,n) if (indeg[i] == 0) q.push(-i);
		int nr = 0;
		while (q.size() > 0) {
			int i = -q.front(); // top() for priority queue
			idx[nr++] = i;
			q.pop();
			trav(e, edges[i])
				if (--indeg[e] == 0) q.push(-e);
		}
		return nr == n;
}
bool vis[300009];
int ans[300009][26];
int fns =0;
void dfs(int v){
	vis[v] = true;
	ans[v][s[v]-'a']=1;
	trav(i,bg[v]){
		rep(k,26){
			ans[v][k] = max(ans[v][k],ans[i][k]);
		}
		ans[v][s[v]-'a'] = max(ans[i][s[v]-'a']+1,ans[v][s[v]-'a']);
	}
	rep(k,26) fns = max(fns,ans[v][k]);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m;cin>>n>>m;
	cin>>s;
	set<int> temp;
	bg.resize(n,temp);
	g.resize(n,temp);
	idx.resize(n);
	rep(i,m){
		int u,v;cin>>u>>v;u--,v--;
		if(u==v){
			cout<<-1;
			return 0;
		}
		g[u].insert(v);bg[v].insert(u);
	}
	if(!topo_sort(g,idx,n)) cout<<-1;
	else{
		rep(i,n){
			dfs(idx[i]);
		}
	cout<<fns;
	}
	return 0;
}