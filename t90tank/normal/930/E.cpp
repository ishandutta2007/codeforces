#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 
const int maxt = maxn * 4; 
const ll mod = 1000000007; 

int k, n, m; 
map<int,int> x; 
pii a[maxn], b[maxn]; 
int tot = 0; 
ll f[maxt][3]; 
ll s[maxt][3]; 
vi pa[maxt]; 
vi pb[maxt]; 
int l[maxt]; 

ll m2(ll k) {
	if (k == 0) return 1; 
	ll r = m2(k/2); 
	r = r * r % mod; 
	if (k & 1) r = r * 2 % mod; 
	return r; 
}

int main() {
	scanf( "%d%d%d", &k, &n, &m ); 
	x[0] = 0; x[k] = 0; 
	for (int i = 1; i <= n; ++i) {
		int l, r; 
		scanf( "%d%d", &l, &r ); 
		a[i] = {l-1,r}; 
		x[l-1] = 0; x[r] = 0; 
	}
	for (int i = 1; i <= m; ++i) {
		int l, r; 
		scanf( "%d%d", &l, &r ); 
		b[i] = {l-1,r}; 
		x[l-1] = 0; x[r] = 0; 
	}
	int pre = 0; 
	for (auto &i : x) {
		tot++; 
		i.sec = tot; 
		l[tot] = i.fir-pre; 
		pre = i.fir; 
	} 
	for (int i = 1; i <= n; ++i) 
		pa[x[a[i].sec]].pb(x[a[i].fir]); 
	for (int i = 1; i <= m; ++i) 
		pb[x[b[i].sec]].pb(x[b[i].fir]); 
	int maxa = 1, maxb = 1; 
	memset(f, 0, sizeof(f)); 
	memset(s, 0, sizeof(s)); 
	f[1][2] = s[1][2] = 1; 
	for (int i = 2; i <= tot; ++i) {
		for (auto p : pa[i]) 
			maxa = max(maxa, p+1); 
		for (auto p : pb[i]) 
			maxb = max(maxb, p+1); 
		f[i][0] = (s[i-1][1]-s[maxa-1][1]+s[i-1][2]-s[maxa-1][2]) % mod; 
		f[i][1] = (s[i-1][0]-s[maxb-1][0]+s[i-1][2]-s[maxb-1][2]) % mod; 
		f[i][2] = (f[i-1][0]+f[i-1][1]+f[i-1][2]) * (m2(l[i])-2) % mod; 
		for (int j = 0; j < 3; ++j) s[i][j] = (s[i-1][j] + f[i][j]) % mod; 
	}
	printf( "%lld\n", ((f[tot][0]+f[tot][1]+f[tot][2])%mod+mod)%mod ); 
}