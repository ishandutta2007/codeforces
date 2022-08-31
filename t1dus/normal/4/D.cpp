#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,w,h;
	cin >> n >> w >> h;
	pii dp[n+5];
	pair<pii,int> a[n+5];
	REP(i,n) cin >> a[i+1].F.F >> a[i+1].F.S,a[i+1].S = i+1;
	sort(a+1,a+n+1);
	dp[0].F = 0;
	dp[0].S = 0;
	int ans = 0,ind = 0;
	FOR(i,1,n+1){
	    if(a[i].F.F <= w or a[i].F.S <= h) {
	        dp[i] = {0,0};
	        continue;
	    }
	    int cur = 0,pos = 0;
	    FOR(j,1,i){
	        if(a[j].F.S < a[i].F.S and a[j].F.F < a[i].F.F){
	            if(dp[j].F > cur){
	                cur = dp[j].F;
	                pos = j;
	            }
	        }
	    }
	    dp[i] = {cur+1,pos};
	    if(dp[i].F > ans){
	        ans = dp[i].F;
	        ind = i;
	    }
 	}
 	vi order;
 	while (ind != 0){
 	    order.pb(ind);
 	    ind = dp[ind].S;
 	}
 	n = order.size();
 	cout << n << "\n";
 	REPD(i,n-1) cout << a[order[i]].S << " ";
}