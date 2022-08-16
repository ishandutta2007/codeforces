/*input
5 6 3
1 2 3 4 5
1 2 3 4 5 6
1 1 10
1 1 -9
1 5 -1
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

int n,m,q,tot = 0;
int a[100005],b[100005],preo[100005],pree[100005];
vi v;

int query(){
	int ind = lower_bound(all(v),tot)-v.begin();
	if(ind == v.size()) ind --;
	int ans = abs(v[ind]-tot);
	if(ind!=v.size()-1) ans = min(ans,abs(v[ind+1]-tot));
	if(ind!=0) ans = min(ans,abs(v[ind-1]-tot));
	return ans;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;
	REP(i,n){
		cin >> a[i];
		if(i%2 == 0) tot += a[i];
		else tot -= a[i];
	}
	pree[0] = preo[0] = 0;
	REP(i,m){
		cin >> b[i];
		if(i%2 == 0) pree[i+1] = b[i];
		else preo[i+1] = b[i];
		preo[i+1] += preo[i];
		pree[i+1] += pree[i];
	}
	REP(j,m-n+1){
		if(j%2 == 0){
			v.pb(pree[n+j]-pree[j]-preo[n+j]+preo[j]);
		}
		else{
			v.pb(preo[n+j]-preo[j]-pree[n+j]+pree[j]);
		}
	}
	// REP(i,v.size()) cout << v[i] << " ";
	// cout << "\n";
	sort(all(v));
	cout << query() << endl;
	WL(q){
		int l,r,x;
		cin >> l >> r >> x;
		if((r-l+1)%2 == 1){
			if(l%2 == 1) tot += x;
			else tot -= x;
		}
		cout << query() << endl;
	}
}