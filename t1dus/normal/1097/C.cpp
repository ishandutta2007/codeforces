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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n;
string a[100005];
vi b[1000005];
pii c[1000005];

signed main(){
  cin >> n;
  REP(i,n){
    cin >> a[i];
    int cur = 0,mn = 0;
    REP(j,a[i].length()){
      if(a[i][j] == '(') cur ++;
      else cur --;
      remin(mn,cur);
    }
    // cout << cur << " " << mn << endl;
    b[cur+500000].pb(mn);
  }
  int ans = 0;
  REP(i,1000005){
    int cnt = 0,cnt2 = 0;
    REP(j,b[i].size()){
      if(b[i][j]>=0) cnt ++;
      if(b[i][j] == i-500000) cnt2++;
    }
    c[i] = {cnt,cnt2};
  }
  FOR(i,-500000,1){
    if(!i) ans += (c[500000].F/2);
    else ans += min(c[i+500000].S,c[-i+500000].F);
  }
  cout << ans << endl;
}