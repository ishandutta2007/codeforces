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
set<int> adj[205];
bitset<205> vis;
int dist[205];

struct edge{
    int u,v;
};

vector<edge> el;

void dfs(int s, int val){
    vis[s] = 1;
    dist[s] = val;
    for(set<int> itr = adj[s].begin(); it != adj[s].end(); it++){
        if (!vis[*it]){
            dfs(*it,val+1);
        }
    }
}

int longest_path(int s){
    fill(dist,dist+205,-1);
    REP(i,205) vis[i] = 0;
    dfs(s,0);
    int next = -1,mx = -1;
    FOR(i,1,n+1){
        if (dist[i] > mx){
            next = i;
            mx = dist[i];
        }
    }
    fill(dist,dist+205,-1);
    REP(i,205) vis[i] = 0;
    dfs(next,0);
    mx = -1;
    FOR(i,1,n+1){
        if (dist[i] > mx){
            mx = dist[i];
        }
    }
    return mx;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin >> n;
    REP(i,n-1){
        int x,y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        edge e;
        e.u = x;
        e.v = y;
        el.pb(e);
    }    
    int ans = 0;
    REP(i,n-1){
        edge e = el[i];
        adj[e.u].erase(e.v);
        adj[e.v].erase(e.u);
        int cur1 = longest_path(e.u);
        int cur2 = longest_path(e.v);
        ans = max(ans,cur1*cur2);
        adj[e.u].insert(e.v);
        adj[e.v].insert(e.u);
    }
    cout << ans << endl;
}