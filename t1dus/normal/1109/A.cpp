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

int n,a[300005],pref[300005];
int cnt_ev[(1<<21)],cnt_od[(1<<21)];

signed main() {
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	pref[0] = 0;
	FOR(i,1,n+1) pref[i] = (pref[i-1]^a[i]);
	FOR(i,1,n+1){
		if(i%2 == 1) cnt_od[pref[i]]++;
		else cnt_ev[pref[i]]++;
	}
	int ans = 0;
	FOR(i,1,n+1){
		if(i%2 == 1){
			// if(cnt_ev.find(pref[i-1]) != cnt_ev.end())
			ans += cnt_ev[pref[i-1]];
			cnt_od[pref[i]]--;
		}
		else{
			// if(cnt_od.find(pref[i-1]) != cnt_od.end())
			ans += cnt_od[pref[i-1]];
			cnt_ev[pref[i]]--;
		}
	}
	cout << ans << endl;
}