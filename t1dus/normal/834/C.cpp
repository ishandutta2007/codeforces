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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
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
	int t; cin >> t;
	vector<ll> v((1e6)+15);
	REP(i,1000015) v[i] = i*i*i;
	WL(t){
	    ll a,b;
	    cin >> a >> b;
	    ll c = a*b;
	    ll c1 = lower_bound(all(v),c)-v.begin();
	    if (pow(c1,3) != c){
	        cout << "No\n"; continue;
	    }
	    if (a%c1 == 0 and b%c1 == 0) cout << "Yes\n";
	    else cout << "No\n";
	}
	
}
// for _ in range(int(input())):
//     a,b = map(int,input().split())
//     c = a*b
//     c1 = round(c**(1/3))
//     if c1**3==c and a%c1==0 and b%c1==0:
//         print("Yes")
//     else:
//         print("No")