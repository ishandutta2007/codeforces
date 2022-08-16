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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int n;
string s;
int a[100005];
int dp[100005][5];

signed main(){
  cin >> n >> s;
  string hard = " hard";
  REP(i,n) cin >> a[i];
  REP(i,100005) REP(j,5) dp[i][j] = 1000000000000000;
  if(s[0] == 'h'){
    dp[1][1] = a[0];
  }
  else{
    dp[1][1] = 0;
  }
  dp[1][2] = dp[1][3] = dp[1][4] = 0;
  FOR(i,2,n+1){
    FOR(j,1,5){
      if(hard[j] == s[i-1]){
        dp[i][j] = min(dp[i-1][j]+a[i-1],dp[i-1][j-1]);
      }
      else dp[i][j] = dp[i-1][j];
    }
  }
  // FOR(i,1,n+1){
  //   REP(j,5){
  //     cout << i << " " << j << " " << dp[i][j] << endl;
  //   }
  // }
  cout << dp[n][4] << endl;
}