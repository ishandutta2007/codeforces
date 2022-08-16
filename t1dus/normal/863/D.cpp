/*input
6 3 5
1 2 3 4 5 6
2 1 3
2 3 6
1 1 6
2 2 1 5 3
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
	
	int n,q,m;
	cin >> n >> q >> m;
	int a[n],t[q],l[q],r[q],b[m];
	REP(i,n) cin >> a[i];
	REP(i,q) cin >> t[i] >> l[i] >> r[i],l[i]--,r[i]--;
	REP(i,m){
		cin >> b[i]; b[i] --;
		// cout << i << " ---------\n";
		REPD(j,q-1){
			// cout << b[i] << " ";
			if(l[j] <= b[i] and b[i] <= r[j]){
				if(t[j] == 1){
					if(b[i] == l[j]) b[i] = r[j];
					else b[i] --; 
				}
				else{
					b[i] = r[j]-b[i]+l[j];
				}
			}
		}
		// cout << b[i] << "\n";
		cout << a[b[i]] << " ";
	}

}