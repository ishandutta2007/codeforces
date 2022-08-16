/*input

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

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,k;
	cin >> n >> m >> k;
	int a[n],b[m]; 
	vector<pii> v;
	REP(i,n) cin >> a[i],v.pb({a[i],1});
	REP(i,m) cin >> b[i],v.pb({b[i],2});
	int n1 = n,m1 = m;
	sort(all(v));
	for(pii x:v){
		if(x.S == 1){
			// cout << x.F << " " << x.S << " " << n1 << " " << m1 << endl;
			if(n1 > m1){
				cout << "YES";
				return 0;
			}
			n1 --;
		}
		else{
			m1 --;
		}
	}
	cout << "NO";
}