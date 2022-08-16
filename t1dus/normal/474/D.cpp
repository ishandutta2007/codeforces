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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t,k;
	cin >> t >> k;
	ll dpr[100005];
	ll dpw[100005];
	ll prefr[100005];
	prefr[0] = 1;
	ll prefw[100005];
	prefw[0] = 1;
	dpr[0] = 1;
	dpw[0] = 0;
	FOR(i,1,k){
	    dpw[i] = 0;
	    dpr[i] = prefw[i-1];
	    prefw[i] = 1;
	    prefr[i] = (prefr[i-1]+dpr[i])%MOD; 
	}
	FOR(i,k,1e5+5){
	    dpw[i] = (dpr[i-k]+dpw[i-k])%MOD;
	    dpr[i] = prefw[i-1];
	    prefr[i] = (prefr[i-1]+dpr[i])%MOD;
	    prefw[i] = (prefw[i-1]+dpw[i])%MOD;
	}
// 	REP(i,6){
// 	    cout << i << " --> " << dpr[i] << " " << dpw[i] << " " << prefr[i] << " " << prefw[i] << endl; 
// 	}
	
	WL(t){
	    ll a,b;
	    cin >> a >> b;
	    cout << (((prefr[b]+prefw[b]-prefw[a-1]-prefr[a-1])%MOD)+MOD)%MOD << endl;
	}
}