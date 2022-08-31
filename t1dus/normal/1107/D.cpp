/*input

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll
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

int n;
bitset<5205> a[5205];
int pref[5205][5205];

bool check(int x){
	// cout << n/x << "--\n";
	REP(i,(n/x)){
		REP(j,(n/x)){
			int gg = pref[x*(i+1)][x*(j+1)]-pref[x*(i+1)][x*j]-pref[x*i][x*(j+1)]+pref[x*i][x*j];
			// cout << i << " " << j << " " << x << " --> " << gg << " ::::" <<  pref[x*i][x*j] << endl;
			if(gg == 0 or gg == x*x) continue;
			return false;
		}
	}
	return true;
}

signed main() {
	scanf("%d",&n);
	FOR(i,1,n+1){
		a[i].reset();
		char s[n/4]; scanf("%s",s);
		REP(j,n/4){
			int x = s[j]-'0';
			if(x > 16) x -= 7;
			if(x >= 8){
				a[i][4*j+1] = 1;
				x -= 8;
			}
			if(x >= 4){
				a[i][4*j+2] = 1;
				x -= 4;
			}
			if(x >= 2){
				a[i][4*j+3] = 1;
				x -= 2;
			}
			if(x >= 1){
				a[i][4*j+4] = 1;
				x -= 1;
			}
		}
	}
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			// cout << a[i][j] << " ";
			pref[i][j] = a[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
		}
		// cout << "\n";
	}
	// cout << " --------------------------\n";
	// FOR(i,1,n+1){
	// 	FOR(j,1,n+1){
	// 		cout << pref[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	int ans = 1;
	FOR(i,2,n+1){
		if(n%i == 0){
			if(check(i)) ans = i;
		}
	}
	cout << ans << endl;
}