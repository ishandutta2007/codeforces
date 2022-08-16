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

int n,m;
int ans = 0;
int fact[1000005],ifact[1000005];

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int C(int x,int y){
	return (((fact[x]*ifact[y])%MOD)*ifact[x-y])%MOD;
}

int f(int x,int y){
	if(x == y) return 1;
	return (y*power(x,x-y-1))%MOD;
}

signed main() {
	cin >> n >> m;
	fact[0] = ifact[0] = 1;
	FOR(i,1,1000001){
		fact[i] = (i*fact[i-1])%MOD;
		ifact[i] = power(fact[i],MOD-2);
	}
	FOR(edges,1,min(n,m+1)){
		int cur = C(n-2,edges-1);
		cur = (cur*C(m-1,edges-1))%MOD;
		cur = (power(m,n-edges-1)*cur)%MOD;
		cur = (cur*f(n,edges+1))%MOD;
		cur = (cur*fact[edges-1])%MOD;
		// cout << edges << " " << cur << endl;
		ans = (ans+cur)%MOD;
	}
	cout << ans << endl;
}