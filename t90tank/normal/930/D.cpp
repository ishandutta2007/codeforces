#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int D = 200006; 

int n; 
vector<pii> s[2]; 
vi h[D]; 
pii be[D]; 
ll ans; 

void maxd(pii &p, int x) {
	p.fir = min(p.fir, x); 
	p.sec = max(p.sec, x); 
}

void solve(vector<pii> p) {
	for (int i = 0; i < D; ++i) h[i].clear(); 
	for (auto i : p) 
		h[i.fir].pb(i.sec); 
	pii t = {D, 1}; 
	for (int i = 0; i < D; ++i) {
		for (auto j : h[i]) maxd(t, j); 
		be[i] = t; 
	}
	t = {D, 1}; 
	for (int i = D-1; i >= 0; --i) {
		ans += max(0, min(t.sec,be[i].sec)-max(t.fir,be[i].fir)); 
		for (auto j : h[i]) maxd(t, j); 
	}
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		int x, y; 
		scanf( "%d%d", &x, &y ); 
		if ((x+y) & 1) 
			s[1].pb({(x+y+D)/2, (x-y+D)/2}); 
		else 
			s[0].pb({(x+y+D)/2, (x-y+D)/2}); 
	}
	ans = 0; 
	for (int p = 0; p <= 1; ++p) solve(s[p]); 
	cout<<ans<<endl; 
}