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

int n,m;
int a[20][10005],b[20][20],c[20][20],dp[17][17][(1<<17)];

int solve(int ind,int last,int mask){
  int cnt = 0;
  REP(i,n){
    if(mask&(1<<i)) cnt++;
  }
  if(cnt == n){
    if(n == 1) return c[0][0];
    return INF;
  }
  else if(dp[ind][last][mask] != -1) return dp[ind][last][mask];
  else if(cnt == n-1){
    int res = 0;
    REP(i,n){
      if(!(mask&(1<<i))){
        remax(res,min(min(b[last][i],solve(ind,i,(mask|(1<<i)))),c[ind][i]));
      }
    }
    return dp[ind][last][mask] = res;
  }
  else{
    int res = 0;
    REP(i,n){
      if(!(mask&(1<<i))){
        remax(res,min(b[last][i],solve(ind,i,(mask|(1<<i)))));
      }
    }
    return dp[ind][last][mask] = res;
  }
}

signed main(){
  cin >> n >> m;
  REP(i,n+1){
    REP(j,n+1){
      REP(k,(1<<(n+1))) dp[i][j][k] = -1;
    }
  }

  REP(i,n){
    REP(j,m){
      cin >> a[i][j];
    }
  }
  REP(i,n){
    REP(j,n){
      int mn = abs(a[i][0]-a[j][0]);
      FOR(k,1,m) remin(mn,abs(a[i][k]-a[j][k]));
      b[i][j] = mn;
    }
  }
  REP(i,n){
    REP(j,n){
      int mn = INF;
      FOR(k,1,m){
        remin(mn,abs(a[i][k]-a[j][k-1]));
      }
      c[i][j] = mn;
    }
  }
  int ans = 0;
  REP(i,n){
    remax(ans,solve(i,i,(1<<i)));
  }
  cout << ans << endl;
}