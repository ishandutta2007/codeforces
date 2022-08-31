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
	
	ll n,m,k;
	cin >> n >> m >> k;
	ll low = 1,high = (n*m),mid,ans;
	while(low <= high){
	    mid = (low+high)/2;
	    ll cnt = 0;
	    for(ll i = 1; i <= n; i++) cnt += min(((mid-1)/i),m);
	    if (cnt < k){
	        ans = mid;
	        low = mid+1;
	    }
	    else high = mid-1;
	}
	cout << ans << endl;
}
/*
n,m,k = map(int,input().split())
low = 1
high = (n*m)
pos = -1
while low <= high:
    mid = (low+high)//2
    cnt = 0
    for i in range(1,n+1):
        cnt += min((mid-1)//i,m)
    if cnt < k:    
        pos = mid
        low = mid+1
    else:
        high = mid-1
        
print(int(pos))
*/