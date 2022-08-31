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

signed main(){
  int t; cin >> t;
  WL(t){
    int n; cin >> n;
    pair<pii,int> a[n+1];
    int ans[n+1];
    REP(i,n){
      cin >> a[i].F.F >> a[i].F.S;
      a[i].S = i;
    }
    sort(a,a+n);
    int x = 0,f = 0;
    REP(i,n){
      remax(x,a[i].F.S);
      if(i != n-1 and x < a[i+1].F.F){
        f = 1;
        REP(j,n){
          if(j <= i) ans[a[j].S] = 1;
          else ans[a[j].S] = 2;
        }
        break;
      }
    }
    if(!f){
      cout << "-1\n";
    }
    else{
      REP(i,n) cout << ans[i] << " "; cout << "\n";
    }
  }
}