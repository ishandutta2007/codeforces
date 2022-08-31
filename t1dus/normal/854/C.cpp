/*input
5 2
4 2 1 10 2
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

int32_t main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin >> n >> k;
	pii a[n+5];
	REP(i,n){
		int x;
		cin >> x;
		a[i] = mp(x,i);
	}
	sort(a,a+n);
	int cost = 0;
	int b[n+5];
	set<int> st;
	FOR(i,k,n+k) st.insert(i);

	set<int> itr;

	REPD(i,n-1){
		it = st.begin();
		int u = *it;
		if(a[i].S > u){
			b[a[i].S] = a[i].S;
			st.erase(a[i].S);
		}
		else{
			cost += a[i].F*(u-a[i].S);
			b[a[i].S] = u;
			st.erase(u);
		}
	}
	cout << cost << endl;
	REP(i,n) cout << b[i]+1 << " ";
}