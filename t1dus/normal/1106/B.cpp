/*input

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
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
int a[100005],c[100005],t,d;
priority_queue<pii,vector<pii>,greater<pii> > pq;

signed main() {
  cin >> n >> m;
  FOR(i,1,n+1){
    cin >> a[i];
  }
  FOR(i,1,n+1){
    cin >> c[i];
    pq.push({c[i],i});
  }
  REP(i,m){
    cin >> t >> d;
    int x = min(a[t],d);
    ans += c[t]*x;
    a[t] -= x;
    d -= x;
    while(d and pq.size()){
      int ind = pq.top().S;
      pq.pop();
      x = min(a[ind],d);
      a[ind] -= x;
      d -= x;
      ans += c[ind]*x;
      if(a[ind]) pq.push({c[ind],ind});
    }
    if(!d) cout << ans << endl;
    else cout << "0\n";
    ans = 0;
  }

}