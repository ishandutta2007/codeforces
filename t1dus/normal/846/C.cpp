/*input
3
-1 2 3
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

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int a[n]; REP(i,n) cin >> a[i];
	int pref[n+1]; pref[0] = 0;
	REP(i,n) pref[i+1] = pref[i]+a[i];
	int ans = -INF;
	int x=0,y=0,z=0;
	REP(i,n+1){
		int cur = pref[i];
		int mx = 0;
		int ind1 = i+1;
		int ind2 = i;
		int sinc = -1;
		int dp = 0;
		int last = 0;
		FOR(j,i+1,n+1){
			if(last > 0){
				dp = last+a[j-1];
			}
			else{
				sinc = j;
				dp = a[j-1];
			}
			if(dp > mx){
				mx = dp;
				ind1 = sinc;
				ind2 = j;
			}
			last = dp;
		}
		if(mx+cur > ans){
			ans = mx+cur;
			x = i;
			y = ind1-1;
			z = ind2;
		}
	}
	cout << x << " " << y << " " << z << "\n";
}