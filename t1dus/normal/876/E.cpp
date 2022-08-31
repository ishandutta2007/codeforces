/*input
4 3
4 3 2 2 1
3 1 1 3
3 2 3 3
2 3 1
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

#define MX 100005

int n,m;
vi a[MX];
vi adj[MX];
bitset<MX> cap;
bitset<MX> ncap;
bitset<MX> vis;

void dfs(int s){
	vis[s] = 1;
	for(auto x: adj[s]){
		if(vis[x]) continue;
		cap[x] = 1;
		dfs(x);
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	REP(i,n){
		int l; cin >> l;
		REP(j,l){
			int x; cin >> x;
			a[i].pb(x);
		}
	}
	FOR(i,1,n){
		int j = 0;
		int ln = min(a[i].size(),a[i-1].size());
		while(j < ln and a[i-1][j] == a[i][j]) j++;
		if(j == ln){
			if(a[i-1].size() > a[i].size()){
				cout << "No\n";
				return 0;
			}
		}
		else if(a[i-1][j] < a[i][j]){
			adj[a[i][j]].pb(a[i-1][j]);
		}
		else{
			cap[a[i-1][j]] = 1;
			ncap[a[i][j]] = 1;
		}
	}
	FOR(i,1,m+1){
		if(cap[i]){
			if(!vis[i]) dfs(i);
		}
	}
	vi ans;
	FOR(i,1,m+1){
		if(cap[i] and ncap[i]){
			cout << "No\n";
			return 0;
		}
		else if(cap[i]) ans.pb(i);
	}
	cout << "Yes\n";
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << " ";
}