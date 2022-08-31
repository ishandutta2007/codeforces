/*input
5
1 5 4 3 2
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

int n,p[100005],c;
bitset<100005> vis;
vi adj[100005];

void dfs(int s){
	c ++;
	vis[s] = 1;
	for(int u:adj[s]){
		if(!vis[u]) dfs(u);
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	FOR(i,1,n+1){
		cin >> p[i];
		adj[i].pb(p[i]);
		adj[p[i]].pb(i);
	}
	vi sz;
	FOR(i,1,n+1){
		if(!vis[i]){
			c = 0;
			dfs(i);
			sz.pb(-c);
		}
	}
	sort(all(sz));
	if(sz.size() == 1) cout << sz[0]*sz[0];
	else{
		int ans = pow(sz[0]+sz[1],2);
		FOR(i,2,sz.size()) ans += sz[i]*sz[i];
		cout << ans;
	}
}