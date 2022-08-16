#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int n; int a[200005], sf[200005];
vi adj[200005];
vi primes[200005];
mii dp[200005];

int ans = 0;

void solve(int u,int p){
  // cout << u << " " << p << endl;
  for(auto v:adj[u]){
    if(v != p) solve(v,u);
  }
  for(auto x:primes[u]){
    int mx = 0,mx2 = 0;
    for(auto v:adj[u]){
      if(v != p){
        if(a[v]%x) continue;
        int lol = dp[v][x];
        if(lol > mx){
          mx2 = mx;
          mx = lol;
        }
        else if(lol > mx2){
          mx2 = lol;
        }
      }
    }
    dp[u][x] = mx+1;
    remax(ans,mx+mx2+1);
  }
}

signed main(){
  FOR(i,2,200001){
    if(sf[i]) continue;
    // cout << i << endl;
    sf[i] = i;
    if (i <= 500){
      for(int j = i*i; j <= 200000; j+=i){
        if(!sf[j]) sf[j] = i;
      }
    }
  }
  cin >> n;
  REP(i,n) cin >> a[i+1];
  FOR(i,1,n+1){
    int x = a[i];
    while(x > 1){
      int y = sf[x];
      primes[i].pb(y);
      while(x%y == 0) x /= y;
    }
  }
  REP(i,n-1){
    int x,y; cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  solve(1,1);
  cout << ans << endl;
}