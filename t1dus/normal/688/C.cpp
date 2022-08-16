/*input
4 2
1 2
2 3
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,m;
vi adj[100005];
int col[100005];

bool bipar(int s,int c,int p){
	col[s] = c;
	for(auto x:adj[s]){
		if(x == p) continue;
		if(col[x] == -1){
			if(!bipar(x,1-c,s)) return false;
		}
		else if(col[x] == col[s]) return false;
	}
	return true;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	REP(i,m){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i,n+1) col[i] = -1;
	FOR(i,1,n+1){
		if(col[i] != -1) continue;
		if(!bipar(i,0,-1)){
			cout << -1;
			return 0;
		}
	}
	vi v[2];
	FOR(i,1,n+1) v[col[i]].pb(i);
	REP(i,2){
		cout << v[i].size() << endl;
		for(auto x: v[i]) cout << x << " ";
		cout << "\n";
	}
}