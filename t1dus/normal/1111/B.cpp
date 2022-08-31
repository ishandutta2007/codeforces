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

int n,k,m,a[100005],pref[100005];

signed main() {
	cin >> n >> k >> m;
	REP(i,n) cin >> a[i];
	sort(a,a+n);
	pref[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i --) pref[i] = pref[i+1]+a[i];
	long double ans = 0;
	REP(i,min(n,m+1)){
		int l = n-i;
		int opl = m-i;
		int sm = pref[i]+min(k*l,opl);
		remax(ans,(long double)(sm)/(long double)(l));
	}
	cout << fixed << setprecision(10) << ans << endl;
}