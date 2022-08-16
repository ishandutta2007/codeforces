#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it;
#define WL(t) while(t --)

int n,k;
vi divs[2005];
ll dp[2005][2005];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> k >> n;
	FOR(i,1,k+1){
	    for (int j = 1; j*j <= i; j++){
	        if (i%j == 0){
	            divs[i].pb(j);
	            if (j*j != i) divs[i].pb(i/j);
	        }
	    }
	}
// 	REP(i,k+1){
// 	    cout << "i -> " << i << "  size -> " << divs[i].size() << endl;
// 	    REP(j,divs[i].size()) cout << divs[i][j] << " ";
// 	    cout << endl;
// 	}
	REP(i,2005) REP(j,2005) dp[i][j] = 0;
	REP(i,k+1) dp[1][i] = 1;
// 	cout << dp[1][1] << endl;
	FOR(i,2,n+1){
	    FOR(j,1,k+1){
	        REP(l,divs[j].size()){
	            dp[i][j] += dp[i-1][divs[j][l]];
	            dp[i][j] %= MOD;
	           // cout << l << " " << divs[j][l] << endl;
	        }
	       // cout << i << " " << j << " " << dp[i][j] << endl;
	    }
	}
    ll ans = 0;
    FOR(i,1,k+1) ans = (ans+dp[n][i])%MOD;
    cout << ans;
}