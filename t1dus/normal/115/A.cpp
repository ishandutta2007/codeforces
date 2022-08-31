#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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

int n;
bitset<2005> vis;
int lev[2005];
vi adj[2005];
int p[2005];
vi start;

int ans = 0;

void dfs(int s, int x){
    vis[s] = 1;
    ans = max(ans,x);
    lev[s] = x;
    REP(i,adj[s].size()){
        if (!vis[adj[s][i]]) dfs(adj[s][i],x+1);
    }
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	FOR(i,1,n+1){
	    cin >> p[i];
	    if (p[i] == -1){ start.pb(i);continue;}
	    adj[i].pb(p[i]);
	    adj[p[i]].pb(i);
	}
	REP(i,n+5) vis[i] = 0;
	FOR(i,0,start.size()){
	    if(!vis[start[i]]) dfs(start[i],1);
	}
	cout << ans << endl;
}