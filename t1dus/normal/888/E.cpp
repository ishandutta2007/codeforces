/*input
5 1000
38361 75847 14913 11499 8297
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

int n,m;
int a[40];
set<int> s;

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	REP(i,n) cin >> a[i];

	int ans = 0;

	REP(i,(1<<(n/2))){
		int cur = 0;
		REP(j,n/2){
			if(i&(1<<j)) cur = (cur+a[j])%m;
		}
		remax(ans,cur);
		s.insert(cur);
		// cout << cur << " ";
	}
	// cout << "------\n";
	REP(i,(1<<((n+1)/2))){
		int cur = 0;
		REP(j,(n+1)/2){
			if(i&(1<<j)) cur = (cur+a[j+(n/2)])%m;
		}

		// cout << cur << " ";

		set<int> itr = s.lower_bound(m-cur);

		if(it != s.begin()) it --;

		remax(ans,cur);
		remax(ans,(cur+(*it))%m);
	}
	// cout << "------\n";
	cout << ans << endl;
}