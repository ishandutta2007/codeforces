#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,m;
vector<pii> adj[100005];
vi g[100005];
vector<pair<pii,int > > edges;
int ans;
vi reversedr;

bool check(int x){
  vi topo;
  int ind[n+5],indeg[n+5];
  REP(i,n+5) indeg[i] = 0;
  REP(i,n+5) g[i].clear();
  FOR(i,1,n+1){
    for (auto u: adj[i]){
      if(u.S > x){
        // cout << x << " " << i << " " << u.F << " " << u.S << endl;
        g[i].pb(u.F);
        indeg[u.F] ++;
      }
    }
  }
  queue<int> q;
  FOR(i,1,n+1){
    if(indeg[i] == 0) q.push(i);
  }
  int cnt = 0;
  while(q.size()){
    int u = q.front();
    // cout << u << endl;
    q.pop();
    cnt ++;
    topo.pb(u);
    for(auto v:g[u]){
      indeg[v] --;
      if(!indeg[v]) q.push(v);
    }
  }
  if(cnt != n) return false;
  REP(i,n){
    ind[topo[i]] = i;
  }
  ans = x;
  reversedr.clear();
  int lol = 0;
  for(auto e:edges){
    lol ++;
    if(e.S > x) continue;
    if(ind[e.F.F] < ind[e.F.S]) continue;
    reversedr.pb(lol);
  }
  return true;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
  REP(i,m){
    int u,v,w; cin >> u >> v >> w;
    edges.pb({{u,v},w});
    adj[u].pb({v,w});
  }
  int low = 0,high = 1000000000,mid;
  while(low <= high){
    mid = (low+high)/2;
    if(check(mid)){
      high = mid-1;
    }
    else low = mid+1;
  }
  cout << ans << " " << reversedr.size() << endl;
  for(auto x:reversedr) cout << x << " "; cout << "\n";
}