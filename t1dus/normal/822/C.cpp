#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 2000000001
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
#define itr ::iterator it
#define WL(t) while(t --)

struct vouc{
    int l,r,cost,type,tot;
};

bool cmp(vouc a, vouc b){
    if (a.type == b.type and b.type == -1){
        return a.l < b.l;
    } 
    else if (a.type == b.type and b.type == 1){
        return a.r < b.r;
    }
    else{
        if (a.type == -1){
            if (a.l != b.r) return a.l < b.r;
            else return true;
        }
        else{
            if (a.r != b.l) return a.r < b.l;
            else return false;
        }
    }
    
    // pair<pii,pii> x,y;
    // if (a.type == -1) x = mp(mp(a.l,-1),mp(a.r,a.cost));
    // else x = mp(mp(a.r,1),mp(a.l,a.cost));
    
    // if (b.type == -1) y = mp(mp(b.l,-1),mp(b.r,b.cost));
    // else y = mp(mp(b.r,1),mp(b.l,b.cost));
    
    // return x < y;
}

vector<vouc> v;
int n,x;
int best[int(3e5)];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> x;
	REP(i,n){
	    vouc a;
	    cin >> a.l >> a.r >> a.cost;
	    a.tot = a.r-a.l+1;
	    a.type = -1;
	    v.pb(a);
	    a.type = 1;
	    v.pb(a);
	}
	sort(all(v),cmp);
	int ans = INF;
	REP(i,3e5) best[i] = INF;
	REP(i,2*n){
	   // printf("%lld %lld %lld %lld %lld\n",v[i].l,v[i].r,v[i].type,v[i].cost,v[i].tot);
	    if (v[i].type == -1){
	        if (v[i].tot > x) continue;
	        ans = min(ans,best[x-v[i].tot]+v[i].cost);
	    }
	    else{
	        best[v[i].tot] = min(best[v[i].tot],v[i].cost);
	    }
	}
	if (ans >= INF) cout << "-1\n";
	else cout << ans << endl;
}