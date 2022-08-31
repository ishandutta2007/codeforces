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
	
	int n;
	cin >> n;
	ll p[n];
	REP(i,n){
	    cin >> p[i];
	}
	ll a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	ll cur = 0;
	ll cnt[5] = {0,0,0,0,0};
	REP(i,n){
	    cur += p[i];
	    if (e <= cur){
	        ll x = cur/e;
	        cnt[4] += x;
	        cur -= e*x;
	    }
	    if (d <= cur){
	        ll x = cur/d;
	        cnt[3] += x;
	        cur -= d*x;
	    }
	    if (c <= cur){
	        ll x = cur/c;
	        cnt[2] += x;
	        cur -= c*x;
	    }
	    if (b <= cur){
	        ll x = cur/b;
	        cnt[1] += x;
	        cur -= b*x;
	    }
	    if (a <= cur){
	        ll x = cur/a;
	        cnt[0] += x;
	        cur -= a*x;
	    }
	}
	REP(i,5) cout << cnt[i] << " ";
	cout << "\n" << cur << "\n";
}