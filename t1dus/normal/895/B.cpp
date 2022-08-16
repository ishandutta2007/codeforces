/*input
8 3 1
1 2 3 4 5 6 5
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
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

int n,x,k,a[100005];
vector<pii> ranges;

void solve(){
	cin >> n >> x >> k;
	if(k == 0){
		REP(i,n){
			cin >> a[i];
			if(a[i]%x != 0){
				int last = a[i]-(a[i]%x);
				int next = last+x;
				ranges.pb({a[i],next-1});
			}
		}
	}
	else{
		REP(i,n){
			cin >> a[i];
			int next = a[i]-(a[i]%x);
			if(next != a[i]) next += x;
			next += (k-1)*x;
			ranges.pb({next,next+x-1});
			// cout << ranges[i].F << " " << ranges[i].S << endl;
		}
	}
	sort(a,a+n);
	int ans = 0;
	REP(i,ranges.size()){
		int ind1 = lower_bound(a,a+n,ranges[i].F)-a;
		int ind2 = upper_bound(a,a+n,ranges[i].S)-a;
		ans += ind2-ind1;
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}