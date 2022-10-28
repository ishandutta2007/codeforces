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

const int maxn = 1e5;
vi adj[maxn];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,m; cin >> n >> m;
	rep(i,m){
		int u,v; cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,n) adj[i].pb(i);
	if(2*m == n*(n-1)){
	   cout << "NO" << endl;
	}else{
 		int i = 0;
		while(sz(adj[i]) == n) i++;
		sort(all(adj[i]));
		int j = 0;
		while(adj[i][j] == j) j++;	
		int c = 3;
		cout << "YES" << endl;
		rep(k,n){
			if(k == i){
				cout << 1 << " ";
			}else if(k == j){
				cout << 2 << " ";
			}else{
				cout << c++ << " ";
			}
		}
		cout << endl;
		c = 3;
		rep(k,n){
			if(k == i){
				cout << 1 << " ";
			}else if(k == j){
				cout << 1 << " ";
			}else{
				cout << c++ << " ";
			}
		}
		cout << endl;
	}
	return 0;
}