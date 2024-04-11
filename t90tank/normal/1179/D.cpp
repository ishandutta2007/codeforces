#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using pll = pair<ll,ll>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 500006; 
ll oo = 0x3f3f3f3f3f3f3f3fll; 

int n; 
vector<pll> Q; 
ll f[maxn]; 
ll s[maxn]; 
vi e[maxn]; 
//s[a], s[b] f[a], f[b] (S-s[a]-s[b])*(S-s[a]-s[b]-1)+f[a]+f[b] 
//(P-s[a])*(Q-s[a])+f[a]+f[b] = P*Q-(P+Q)*s[a]+s[a]^2+f[a]

ll xmul(pll a, pll b, pll c) {
	b.fir -= a.fir; 
	b.sec -= a.sec; 
	c.fir -= a.fir; 
	c.sec -= a.sec;  
	return b.fir * c.sec - b.sec * c.fir; 
}
vector<pll> c;

ll solve() {
	if (Q.size() < 2) return oo; 
	ll ret = oo; 
	for (auto &p : Q)
		p.sec += p.fir * p.fir; 
	sort(Q.begin(), Q.end()); 
	c.clear(); 
	for (int i = 0; i < (int)Q.size(); ++i) {
		auto p = Q[i]; 
		ll pp = n-p.fir; 
		ll qq = n-p.fir-1; 
		int x; 
		while (c.size() >= 2) {
			x=(int)c.size()-1;
			if (pp*qq-(pp+qq)*c[x].fir+c[x].sec < pp*qq-(pp+qq)*c[x-1].fir+c[x-1].sec) break; 
				c.pop_back(); 
		}
		if (!c.empty())
			ret = min(ret, pp*qq-(pp+qq)*c.back().fir+c.back().sec+p.sec-p.fir*p.fir); 
		while (c.size() >= 2 && xmul(c.back(), c[(int)c.size()-2], p) <= 0) 
			 c.pop_back(); 
		c.pb(p); 
	}/*
	int x = (int)c.size()-1; 
	for (int i = 0; i < (int)Q.size(); ++i) {
		auto p = Q[i]; 
		while (x > 0 && (pp*qq-(pp+qq)*c[x].fir+c[x].sec >= pp*qq-(pp+qq)*c[x-1].fir+c[x-1].sec))
			x--; 
		if (i == num[x]) {
			if (x > 0) ret = min(ret, pp*qq-(pp+qq)*c[x-1].fir+c[x-1].sec+p.sec-p.fir*p.fir); 
			if (x + 1 < (int)c.size()) ret = min(ret, pp*qq-(pp+qq)*c[x+1].fir+c[x+1].sec+p.sec-p.fir*p.fir); 
		}
		else {
			//printf("%lld,%lld,%lld,%lld=%lld\n", p.fir, p.sec, c[x].fir, c[x].sec, pp*qq-(pp+qq)*c[x].fir+c[x].sec+p.sec-p.fir*p.fir); 
			ret = min(ret, pp*qq-(pp+qq)*c[x].fir+c[x].sec+p.sec-p.fir*p.fir); 
		}
	}*/
	//for (auto p : Q) 
		//cout<<p.fir<<','<<p.sec<<' '; 
	//puts( "" ); 
	//cout<<ret<<endl; 
	return ret; 
}

ll ans; 

void dfs(int x, int p) {
	f[x] = oo;
	s[x] = 1; 
	for (auto i : e[x]) 
		if (i != p) {
			dfs(i, x); 
			s[x] += s[i];
		}
	Q.clear();
	for (auto i : e[x]) 
		if (i != p) 
			Q.pb({s[i], f[i]}); 
	ans = min(ans, solve()); 
	for (auto i : e[x]) 
		if (i != p) 
			f[x] = min(f[x], f[i] + (s[x]-s[i]) * (s[x]-s[i]-1)); 
	if (s[x] == 1) f[x] = 0; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		scanf( "%d%d", &u, &v ); 
		e[u].pb(v); 
		e[v].pb(u); 
	}
	ans = oo; 
	dfs(1, 0);
	ans = min(ans, f[1]); 
	cout<<(n*ll(n-1)*2-ans)/2<<endl;  
}