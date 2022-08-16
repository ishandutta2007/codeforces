/*input
3 3
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

int n,k;
vi a;

void unsort(int l,int r){
	if(l == r) return;
	if(k){
		k -= 2;
		int mid = (l+r-1)/2;
		unsort(l,mid);
		unsort(mid+1,r);
	}
	else{
		sort(a.begin()+l,a.begin()+r+1);
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	REPD(i,n-1) a.pb(i+1);
	if(k%2 == 0){
		cout << -1; return 0;
	}
	k --;
	unsort(0,n-1);
	if(k) cout << -1;
	else{
		for(auto x:a) cout << x << " ";
	}
}