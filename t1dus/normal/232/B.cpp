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

ll power(ll a,ll b,ll m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	ll x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,k,pewd[105][105],dp[105][10005],C[205][205];
ll m;

signed main(){
  cin >> n >> m >> k;
  REP(i,205){
    REP(j,205){
      if(i < j) C[i][j] = 0;
      else if(j == 0 or i == j) C[i][j] = 1;
      else C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
    }
  }
  REP(i,n+1){
    ll times = m/n;
    if(m%n >= i) times++;
    REP(l,n+1){
      pewd[i][l] = power(C[n][l],times);
    }
    REP(j,k+1){
      if(i == 0){
        if(j == 0) dp[i][j] = 1;
        else dp[i][j] = 0;
      }
      else{
        REP(l,n+1){
          if(l > j) break;
          dp[i][j] += (1LL*dp[i-1][j-l]*pewd[i][l])%MOD;
          dp[i][j] %= MOD;
        }
      }
    }
  }
  cout << dp[n][k] << endl;
}