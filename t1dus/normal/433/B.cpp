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
#define int ll

int32_t main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	int a[n+5],b[n+5],pref1[n+5],pref2[n+5];
	pref1[0] = 0,pref2[0] = 0;
	REP(i,n) {
	    cin >> a[i];b[i]=a[i];
	}
	sort(b,b+n);
	REP(i,n){
	    pref1[i+1] = pref1[i]+a[i];
	    pref2[i+1] = pref2[i]+b[i];
	}
	int q;
	cin >> q;
	WL(q){ 
	    int t,l,r;
	    cin >> t >> l >> r;
	    if(t == 1) cout << pref1[r]-pref1[l-1];
	    else cout << pref2[r]-pref2[l-1];
	    cout << "\n";
	}
}