#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
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

vi adj[105][105];
bool vis[105];
int n,m,q;

void dfs(int s,int col){
    vis[s] = true;
    for(auto x:adj[col][s]){
        if(!vis[x]) dfs(x,col);
    }
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	REP(i,m){
	    int u,v,c;
	    cin >> u >> v >> c;
	    adj[c][u].pb(v);
	    adj[c][v].pb(u);
	}
	cin >> q;
	WL(q){
	    int u,v;
	    cin >> u >> v;
	    int ans = 0;
	    FOR(i,1,101){
	        FOR(j,1,101) vis[j] = false;
	        dfs(u,i);
	        if(vis[v]) ans ++;
	    }
	    cout << ans << endl;
	}
}