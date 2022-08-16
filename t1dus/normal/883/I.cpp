/*input
10 4
810 8527 9736 3143 2341 6029 7474 707 2513 2023
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

#define MX 300005

int n,k;
int a[MX]; // dp[i] is ans for subarray a[1],a[2],a[3].... a[i]. // 1-indexed 
bool pos[MX];

bool solve(int diff){
	int cnt = k-1;
	REP(i,k+1) pos[i] = 0;
	int cur = 1;
	pos[0] = 1;
	if(a[k]-a[1] <= diff) pos[k] = 1;

	FOR(i,k+1,n+1){
		while(a[i]-a[cur] > diff and cur <= n) cur ++;
		while(!pos[cur-1] and cur <= n) cur ++;
		if(cur <= i-k+1) pos[i] = 1;
		else pos[i] = 0;
	}
	return pos[n];
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	REP(i,n) cin >> a[i+1];
	sort(a+1,a+n+1);
	// REP(i,n+1) cout << a[i] << " "; cout << endl; 
	int low = 0,high = INF,mid,ans = INF;
	while(low <= high){
		mid = (low+high)/2;
		if(solve(mid)){
			high = mid-1;
			ans = mid;
		}
		else low = mid+1;
	}
	cout << ans << endl;
}