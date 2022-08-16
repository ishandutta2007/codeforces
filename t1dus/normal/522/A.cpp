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

int n;
vi adj[405];
bitset<405>vis;
map<string,int> d;
int dist[405];

void dfs(int s){
    vis[s] = true;
    for(auto x:adj[s]){
        if(vis[x]) continue;
        dist[x] = dist[s]+1;
        dfs(x);
    }
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int cur = 0;
	REP(i,n){
	    int u,v;
	    string u1,v1,xyz;
	    cin >> u1 >> xyz >> v1;
	    REP(j,u1.length()) u1[j] = tolower(u1[j]);
	    REP(j,v1.length()) v1[j] = tolower(v1[j]);
	   // cout << u1 << " - " << v1 << endl;
	    if(d.find(u1) != d.end()) u = d[u1];
	    else{
	        d[u1] = cur;
	        u = cur++;
	    }
	    if(d.find(v1) != d.end()) v = d[v1];
	    else{
	        d[v1] = cur;
	        v = cur++;
	    }
	   // cout << u << " - " << v << endl; 
	    adj[u].pb(v);
	   // adj[v].pb(u);
	}
	int ans = 0;
	REP(i,cur){
	  REP(j,cur) dist[j] = -1,vis[j] = 0;
	  dist[i] = 1;
	  dfs(i);
	  REP(j,cur) ans = max(ans,dist[j]);
	}
	cout << ans << endl;
}