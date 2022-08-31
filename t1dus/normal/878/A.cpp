/*input
3
& 1
& 3
& 5
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
	
	int n; cin >> n;
	int a = 0,b = 0,c = 0,d = 0,e = 1023;
	REP(i,n){
		int x;char y;
		cin >> y >> x;
		if(y == '|') (d |= x),(e |= x);
		else if(y == '^') (d ^= x), (e ^= x);
		else (d &= x), (e &= x);
 	}
 	// cout << d << " " << e << endl;
 	REP(i,10){
 		int lol1 = ((1<<i)&d);
 		int lol2 = ((1<<i)&e);
 		// cout << lol1 << " " << lol2 << endl;
 		if(lol1 and lol2){
 			a += (1<<i);
 		}
 		else if(lol1 and (!lol2)){
 			b += (1<<i);
 		}
 		else if((!lol1) and (!lol2)){
 			c += (1<<i);
 		}
 	}
 	cout << "3\n" << "| " << a << "\n^ " << b << "\n& " << 1023-c;
}