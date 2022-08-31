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

int n;
int depth[100005];
long double prob[100005];
vi adj[100005];

void dfs(int s,int par,int dep){
  depth[s] = dep;
  for(auto x:adj[s]){
    if(x != par){
      if(s == 1){
        prob[x] = adj[s].size();
      }
      else{
        prob[x] = prob[s]*(adj[s].size()-1);
      }
      dfs(x,s,dep+1);
    }
  }
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	if(n == 1){
	  cout << 0 << "\n";
	  return 0;
	}
	REP(i,n-1){
	  int u,v;
	  cin >> u >> v;
	  adj[u].pb(v);adj[v].pb(u);
	}
	prob[1] = 1;
	dfs(1,-1,0);
	long double ans = 0;
	FOR(i,2,n+1){
	  if(adj[i].size() == 1) ans += depth[i]/prob[i];
	}
	cout << setprecision(20);
	cout << ans << endl;
}