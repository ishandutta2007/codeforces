/*input

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll
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
vi perm;
bitset<100005> vis;
priority_queue<int> pq;

signed main() {
	cin >> n >> m;
	REP(i,m){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pq.push(-1);
	vis[1] = 1;
	while(!pq.empty()){
		int u = -pq.top();
		pq.pop();
		perm.pb(u);
		for(auto v:adj[u]){
			if(!vis[v]){
				vis[v] = 1;
				pq.push(-v);
			}
		}
	}
	for(auto x:perm) cout << x << " "; cout << "\n";
}