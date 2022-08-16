/*input
2
2 2
*/		
#include <bits/stdc++.h>
using namespace std;

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
#define int ll

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int a[n];
	int tot = 0;
	REP(i,n) cin >> a[i],tot+=a[i];
	if(tot%2){
		cout << "First\n";
	}
	else{
		int pref[n+1];
		pref[0] = 0;
		REP(i,n) pref[i+1] = pref[i]+a[i];
		int f = -1,s = -1;
		REP(i,n){
			if(a[i]%2){
				if(f == -1) f = i;
				s = i;
			}
		}
		if(f == -1){
			cout << "Second\n";
		}
		else{
			if((pref[s+1]-pref[0])%2 == 0){
				cout << "First\n";
			}
			else{
				cout << "Second\n";
			}
		}
	}
}