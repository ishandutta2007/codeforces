/*input
5
1 2
2 3
3 4
4 5
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

vi adj[100005];
int col[100005];

void dfs(int s,int p,int c){
	col[s] = c;
	for(int i = 0; i < adj[s].size(); i++){
		int u = adj[s][i];
		if(u == p) continue;
		if(col[u] == -1) dfs(u,s,1-c);
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	REP(i,n+5){
		adj[i].clear();
		col[i] = -1;
	}
	REP(i,n-1){
		int u,v;
		cin >> u >> v;
		u --;
		v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1,0);
	int x = 0,y = 0;
	REP(i,n){
		if(col[i] == 0) x++;
		else y ++;
	}
	cout << (x*y)-(n-1);
}