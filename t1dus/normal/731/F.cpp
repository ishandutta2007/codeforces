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
#define int ll

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int a[n];
	int tot = 0;
	REP(i,n) cin >> a[i],tot+=a[i];
	sort(a,a+n);
	set<int> s;
	int ans = 0;
	REP(i,n){
	    if(s.find(a[i]) != s.end()) continue;
	    int cur = 0;
	    for(int x = 1; x*a[i] <= 200000; x++){
	        s.insert(x*a[i]);
	        int cnt = lower_bound(a,a+n,a[i]*(x+1))-lower_bound(a,a+n,a[i]*x);
	        cur += cnt*x*a[i];
	    }
	    ans = max(ans,cur);
	}
	cout << ans << endl;
}