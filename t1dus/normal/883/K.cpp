/*input
3
1 1
100 100
1 1
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

#define MX 1000005

int n,s[MX],g[MX],a[MX];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n) cin >> s[i+1] >> g[i+1];
	REP(i,n) a[i+1] = s[i+1]+g[i+1];
	FOR(i,2,n+1){
		a[i] = min(a[i],a[i-1]+1);
	}
	FORD(i,n-1,1){
		a[i] = min(a[i],a[i+1]+1);
	}
	int ans = 0;
	bool flag = false;
	FOR(i,1,n+1){
		ans += a[i]-s[i];
		if(a[i] < s[i]) flag = true;
	}

	if(ans < 0 or flag){
		cout << -1;
	}
	else{
		cout << ans << "\n";
		FOR(i,1,n+1) cout << a[i] << " ";
	}

}