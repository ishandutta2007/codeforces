#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 666; 
const ll mod = 1000000007; 

bool check(ll x) {
	ll m = (ll)sqrt(db(x)); 
	for (ll i = m - 100; i <= m+100; ++i) 
		if (i*i == x) return true; 
	return false; 
}


vector<int> s; 
bool v[maxn]; 
ll a[maxn]; 
int n; 
int m; 
ll f[maxn][maxn]; 
ll P[maxn][maxn]; 
ll C[maxn][maxn]; 
ll fac[maxn]; 

int main() {
	C[0][0] = 1; 
	for (int i = 1; i < maxn; ++i) {
		C[i][0] = 1; 
		for (int j = 1; j < maxn; ++j) 
			C[i][j] = (C[i-1][j-1]+C[i-1][j]) % mod; 
	}
	for (int i = 0; i < maxn; ++i) {
		P[i][0] = 1; 
		for (int j = 1; j < maxn; ++j) P[i][j] = (P[i][j-1] * i) % mod; 
	}
	fac[0] = 1; 
	for (int i = 1; i < maxn; ++i) fac[i] = fac[i-1] * i % mod; 
	
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%lld", &a[i] ); 
	s.pb(0); 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) {
			int ss = 1; 
			for (int j = i+1; j <= n; ++j) 
				if (!v[j] && check(a[i]*a[j])) {
					v[j] = true; 
					ss++; 
				}
			s.pb(ss); 
		}
		
	int sum = 0; 
	memset(f, 0, sizeof(f)); f[0][1] = 1; 
	for (int i = 1; i < (int)s.size(); ++i) {
		//cout<<s[i]<<endl; 
		for (int j = 1; j <= sum+1; ++j) {
			//cout<<i-1<<' '<<j<<' '<<f[i-1][j]<<endl; 
			for (int k = 0; k <= min(s[i],j); ++k) 
				for (int l = 0; l+k <= s[i]; ++l) 
					if (s[i]-l-k <= 2*(j-k)) {
						ll tmp; 
						if (j-k == 0) {
							if (l > 0) tmp = 0; 
							else tmp = 1; 
						}
						else tmp = C[j-k+l-1][l]; 
						(f[i][j-k+l] += f[i-1][j] * C[2*(j-k)][s[i]-l-k] % mod * tmp % mod * C[j][k] % mod) %= mod; 
					}
		}
		sum += s[i]; 
	}
	ll ans = f[s.size()-1][0]; 
	for (auto i : s) (ans *= fac[i]) %= mod; 
	
	cout<<ans<<endl; 
}