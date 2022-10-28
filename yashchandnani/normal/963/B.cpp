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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi g[200009];
vector<vi> g2;
int cnt[200009];
void dfs(int v,int p){
	trav(i,g[v]){
		if(i==p||i==0) continue;
		dfs(i,v);
		if(cnt[i]==1) g2[i].pb(v);
		else g2[v].pb(i);
		cnt[v]^=(cnt[i]^1);
	}
}
bool topo_sort(vector<vi>  &edges, vi &idx, int n) {
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
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	g2.resize(n+1);
	repA(i,1,n){
		int x;cin>>x;
		g[x].pb(i);
		g[i].pb(x);
	}
	if(n%2==0){
			cout<<"NO";return 0;
	}
	dfs(1,0);
	vi idx(n+1,0);
	if(topo_sort(g2,idx,n+1)){
		cout<<"YES\n";
		trav(i,idx) if(i!=0) cout<<i<<'\n';
	}
	else{
		cout<<"NO";
	}
	return 0;
}