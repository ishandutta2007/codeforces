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

int n,m,ans = 0;
vi adj[100005];
bitset<100005>a;

void dfs(int s,int par,int cnt){
  if(a[s]) cnt ++;
  else cnt = 0;
  if(cnt > m) return;
  if(s != 1 and adj[s].size() == 1){ans++;return;}
  for(auto x:adj[s]){
    if(x != par) dfs(x,s,cnt);
  }
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	REP(i,n){
	  int xyz;cin>>xyz;
	  a[i+1]=xyz;
	}
	REP(i,n-1){
	    int u,v;
	    cin >> u >> v;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	dfs(1,-1,0);
	cout << ans << endl;
}