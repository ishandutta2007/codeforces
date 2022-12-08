#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;  

typedef long long ll; 

ll n, m; 
int a[maxn]; 
int v[maxn]; 

ll getmul(ll x, ll k) {
	if (k == 0) return 1; 
	ll ret = getmul(x, k/2); 
	ret = ret * ret % m; 
	if (k & 1) ret = ret * x % m; 
	return ret;
}

ll inv(ll x) {
	return getmul(x, m-2); 
}
map<int,int> nxt; 
map<int,int> S; 
map<int,bool> V; 
int dfs(int x) {
	//cout<<x<<' '<<nxt[x]<<' '<<S.count(x)<<' '<<S[x]<<' '<<V[x]<<endl; 
	//for (int i = 1; i <= 200000000; i++); 
	if (S.count(x) == 0) return 0; 
	if (S[x] != 0) return S[x]; 
	if (nxt[x] == x || V[nxt[x]]) S[x] = -1000000000; 
	else {
		V[x] = true; 
		S[x] = dfs( nxt[x] ) + 1; 
		V[x] = false; 
	}
	return S[x]; 
}

void solve(ll &a1, ll &d) {
	//cout<<m<<' '<<n<<endl; 
	if (n > m) {
		memset(v, 0, sizeof(v)); 
		for (int i = 1; i <= n; ++i) v[a[i]]++; 
		int u = n / m; 
		n = 0; 
		for (int i = 0; i < m; ++i) 
			if (v[i] < u) {
				a1 = d = 0; 
				return; 
			}
			else 
				for (int j = 1; j <= v[i]-u; ++j) 
					a[++n] = i; 
		solve(a1,d); 
		return; 
	}
	if (n > m/2) {
		memset(v, 0, sizeof(v)); 
		for (int i = 1; i <= n; ++i) v[a[i]] = 1; 
		n = 0; 
		for (int i = 0; i < m; ++i) 
			if (v[i]==0) a[++n] = i; 
		solve( a1, d ); 
		a1 = (a1+m-d) % m; 
		d = (m-d) % m; 
		return; 
	}
	if (n == 1) {
		a1 = a[1]; 
		d = 1; 
		return; 
	}
	ll s = 0; 
	for (int i = 1; i <= n; ++i) s = (s+a[i]) % m; 
	s = s * inv(n) % m; 
	nxt.clear(); 
	S.clear(); 
	V.clear(); 
	for (int i = 1; i <= n; ++i) {
		if (n % 2 == 0) nxt[a[i]] = ((a[i]+m-s)*2+a[i]) % m; 
		else nxt[a[i]] = (a[i]+m-s+a[i]) % m; 
		S[a[i]] = 0; 
	}
	//for (int i = 1; i <= n; ++i) printf( "%d\n", a[i] );  
	for (int i = 1; i <= n; ++i) dfs(a[i]); 
	int ans=-1,ansf; 
	for (auto p : S)
		if (ans==-1 || p.second>ansf) {
			ans = p.first; 
			ansf = p.second; 
		}
	d = (ans-s+m)%m; 
	//cout<<s<<' '<<a[1]<<' '<<a[2]<<' '<<ans<<endl; 
	if (n % 2 == 0) d = d*2%m;  
	a1 = ((s*2-(n-1)*d)%m*inv(2)%m+m)%m; 
	//cout<<a1<<' '<<d<<endl; 
}

int main() {
	cin>>m>>n; 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	map<int,int> Q; 
	for (int i = 1; i <= n; ++i) Q[a[i]]++; 
	if (Q.size() == 1) {
		printf( "%d 0\n", a[1] ); 
		return 0; 
	}
	ll a1, d; 
	int N = n; 
	solve(a1, d);
	//cout<<a1<<' '<<d<<endl; 
	for (int i = 0; i < N; ++i) 
		if (Q[(a1+i*d) % m] == 0) {
			printf( "-1\n" ); 
			return 0; 
		}
		else {
			Q[(a1+i*d) % m]--; 
		}
	cout<<a1<<' '<<d<<endl; 
}