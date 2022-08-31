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

signed main(){
  int n; cin >> n;
  string s; cin >> s;
  int pref[n+5];
  pref[0] = 0;
  int cnt = 0,mn = 0;
  REP(i,n){
    if(s[i] == '(') cnt++;
    pref[i+1] = 2*cnt-i-1;
    remin(mn,pref[i+1]);
  }
  if(n%2 == 1) cout << "0\n";
  else if(cnt == (n-2)/2){
    if(mn < -2) cout << "0\n";
    else{
      int ans = 0;
      REP(i,n){
        if(s[i] == ')'){
          ans ++;
          if(pref[i+1] < 0) break;
        }
      }
      cout << ans << endl;
    }
  }
  else if(cnt == (n+2)/2){
    string s1 = s;
    REP(i,n){
      if(s[i] == ')') s1[i] = '(';
      else s1[i] = ')';
    }
    REP(i,n){
      s[i] = s1[n-i-1];
    }
    cnt = 0,mn = 0;
    REP(i,n){
      if(s[i] == '(') cnt++;
      pref[i+1] = 2*cnt-i-1;
      remin(mn,pref[i+1]);
    }
    if(mn < -2) cout << "0\n";
    else{
      int ans = 0;
      REP(i,n){
        if(s[i] == ')'){
          ans ++;
          if(pref[i+1] < 0) break;
        }
      }
      cout << ans << endl;
    }
  }
  else cout << "0\n";
}