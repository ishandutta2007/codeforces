/*input
4
6 3
4 2
1 3
3 1
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

#define MX 2000005

int fact[MX],ifact[MX];
int sf[MX];

int x,y;

int C(int n,int r){
	// cout << n << " " << r << " " << (((fact[n]*ifact[r])%MOD)%ifact[n-r])%MOD << endl;
	return (((fact[n]*ifact[r])%MOD)*ifact[n-r])%MOD;
}

void solve(){
	cin >> x >> y;
	if(x == 1){
		cout << power(2,y-1)%MOD << endl;
		return;
	}
	else if(y == 1){
		cout << "1\n";
		return;
	}
	vi pws;
	int ans = 1;
	while(x != 1){
		// cout << x << " " << sf[x] << endl;
		int cur = 0;
		int lol = sf[x];
		while(x%lol == 0 and x != 1){
			x /= sf[x];
			cur ++;
		}
		// cout << cur << " -- " << C(y+cur-1,y-1) << " -- ";
		ans *= C(y+cur-1,y-1)%MOD;
		// cout << ans << "--\n";
		ans %= MOD;
	}
	ans *= power(2,y-1);
	ans %= MOD;
	cout << ans << endl;

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = ifact[0] = 1;

	FOR(i,1,2000001){
		fact[i] = (i*fact[i-1])%MOD;
		ifact[i] = power(fact[i],MOD-2)%MOD;
	}

	REP(i,MX) sf[i] = -1;

	FOR(i,2,2000001){
		if(sf[i] == -1){
			sf[i] = i;
			for(int j = i; j <= 2000000; j += i){
				if(sf[j] == -1) sf[j] = i;
			}
		}
	}

	int t = 1;
	cin >> t;
	WL(t) solve();
}