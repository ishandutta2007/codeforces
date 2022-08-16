/*input
5
2 2 3 4 6
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

int n,a[2005];

int reform(int x){
	int c = 3;
	int res = 1;
	if(x%2 == 0) res = 2;
	while(x%2 == 0) x /= 2;
	while(c*c <= x){
		if(x%c == 0){
			res *= c;
			while(x%c == 0) x /= c;
		}
		c += 2;
	}
	if(x > 1) res *= x;
	return res;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n) cin >> a[i],a[i] = reform(a[i]);
	
	int g = a[0],cnt = 0;

	REP(i,n){
		if(a[i] == 1) cnt ++;
		g = gcd(g,a[i]);
	}

	if(g > 1) {cout << "-1\n"; return 0;}
	if(cnt) {cout << n-cnt << endl; return 0;}

	int res = INF;

	REP(i,n){
		g = a[i];int l = 1;
		FOR(j,i+1,n){
			g = gcd(a[j],g);
			l ++;
			if(g == 1){
				remin(res,l);
				break;
			}
		}
	}
	cout << 2*(res-1)+(n-res) << endl;
}