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

int n,k,A,B,a[100005];

int solve(int x,int y){
	int l = lower_bound(a,a+k,x)-a;
	int r = lower_bound(a,a+k,y+1)-a;
	if(l == r) return A;
	int ans = (y-x+1)*(r-l)*B;
	int mid = (x+y)/2;
	if(x != y) remin(ans,solve(x,mid)+solve(mid+1,y));
	return ans;
}

signed main() {
	cin >> n >> k >> A >> B;
	REP(i,k) cin >> a[i];
	sort(a,a+k);
	cout << solve(1,(1<<n)) << endl;
}