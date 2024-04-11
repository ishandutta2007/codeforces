
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 19;
int pa[MAXN];
bool visited[MAXN];
vi adj[MAXN];
double pp[MAXN], p[MAXN];

void dfs(int n){
	visited[n] = true;
	trav(it,adj[n]){
		if(!visited[it]){
 			pp[n] += p[it];
			pa[it] = n;
			dfs(it);
		}	
	}
	return;
}
	
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
	cout << setprecision(10);
	int n; cin >> n;
	rep(i,n) {float temp; cin >> temp; p[i] = temp;}
	rep(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int q; cin >> q;
	pa[0] = -1;
	dfs(0);
	double ans = 0;
	repA(i,1,n-1){
		ans += p[pa[i]]*(1-p[i]);
	}
	ans += (1-p[0]);
	rep(i,q){
		int in; cin >> in;
		float temp; cin >> temp;
		double np; np = temp;
		
		if(in == 0){
			ans -= (1-p[0]);
			ans += (1- np);
			ans -= p[0] * (sz(adj[0]) - pp[0]);
			ans += np * (sz(adj[0]) - pp[0]);
			p[0] = np;
		}else{
			ans -= p[pa[in]]*(1-p[in]);
			ans += p[pa[in]]*(1-np);
			pp[pa[in]] -= p[in];
			pp[pa[in]] += np;
			if(sz(adj[in]) != 0){ 
				ans -= p[in]*((sz(adj[in])-1)-pp[in]);
				ans += np*((sz(adj[in])-1)-pp[in]);
			}
			p[in] = np;
		}
		cout << ans << '\n';
	}
	return 0;
}