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

int a[100005],b[100005],prefa[100005],prefb[100005];
int n,m,low = 0,high = 0,mid,ans = -1;

int solve(int md){
  int x1 = lower_bound(a+1,a+n+1,md)-(a+1);
  int c1 = x1*md-prefa[x1];
  int x2 = lower_bound(b+1,b+m+1,md)-(b+1);
  int c2 = (prefb[m]-prefb[x2])-(md*(m-x2));
  return c1+c2;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	REP(i,n) cin >> a[i+1],remax(high,a[i+1]);
	REP(i,m) cin >> b[i+1],remax(high,b[i+1]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	prefa[0] = 0;
  prefb[0] = 0;
	FOR(i,1,n+1) prefa[i] = prefa[i-1]+a[i];
	FOR(i,1,m+1) prefb[i] = prefb[i-1]+b[i];
	while(low <= high){
	  mid = (low+high)/2;
	  int a1 = solve(mid-1),a2 = solve(mid),a3 = solve(mid+1);
	  if (a1 >= a2 and a3 >= a2){
	    ans = a2;
	    break;
	  }
	  if(a1 >= a2){
	    low = mid+1;
	  }
	  else{
	    high = mid-1;
	  }
	}
	cout << ans << endl;
}