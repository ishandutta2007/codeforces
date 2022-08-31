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

vi adj[100005];
set<int> v[100005];
bool vis[100005];
int c[100005];
int n,m;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n >> m;
    REP(i,100005) vis[i] = false;
    REP(i,n) cin >> c[i+1];
    REP(i,n) vis[c[i+1]] = true;
    REP(i,m){
        int u,x;
        cin >> u >> x;
        adj[u].pb(x);adj[x].pb(u);
        if(c[u] != c[x]){
            v[c[u]].insert(c[x]);
            v[c[x]].insert(c[u]);
        }
    }
    int cur = -1,ind = -1;
    FOR(i,1,100005){
        int sz = v[i].size();
        // cout << i << " " << sz << endl;
        if(sz > cur and vis[i]){
            // cout << "lulz\n";
            cur = sz;
            ind=i;
        }
    }
    cout << ind << endl;
}