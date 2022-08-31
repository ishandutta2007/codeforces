/*input
1 0
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
	
	int n,m;
	cin >> n >> m;
	int k[105],f[105];
	REP(i,m) cin >> k[i] >> f[i];
	set<int> pos;
	REP(i,200) pos.insert(i+1);
	REP(i,m){
		// x*f[i] >= k[i]
		// x*(f[i]-1) < k[i]
		FOR(x,1,201){
			if((!(x*f[i] >= k[i])) or (!(x*(f[i]-1) < k[i]))){
				if(pos.find(x)!=pos.end()) pos.erase(x);
			}
		}
	}
	// for(set<int> itr = pos.begin(); it != pos.end(); it++) cout << *it << " ";
	// cout << "\n";
	set<int> ans;
	for(set<int> itr = pos.begin(); it != pos.end(); it++){
		ans.insert((n+(*it)-1)/(*it));
	}
	if(ans.size() == 1) cout << *ans.begin();
	else cout << -1;
	// assert(pos.size() != 0);
}