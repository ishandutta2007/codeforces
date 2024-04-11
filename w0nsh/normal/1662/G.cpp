#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
using vi = vector<int>;
using ll = long long;

constexpr int N = 1e6 + 5;
constexpr int INF = 0x3f3f3f3f;

ll rozm[N], dp_dol[N], dp_gora[N];
vi G[N];
int n;
int par[N];

int SZ;
std::vector<int> CEN;
int szdfs(int v, int p){
	int sz = 1;
	bool good = true;
	for(auto ch : G[v]){
		if(ch == p) continue;
		int cur = szdfs(ch, v);
		sz += cur;
		if(2 * cur > SZ) good = false;
	}
	if((SZ - sz) * 2 > SZ) good = false;
	if(good) CEN.push_back(v);
	return sz;
}

void rozmdfs(int v, int p) {
	rozm[v] = 1;
	dp_dol[v] = 0;
	for(auto ch : G[v]) {
		if(ch == p) continue;
		rozmdfs(ch, v);
		rozm[v] += rozm[ch];
		dp_dol[v] += dp_dol[ch];
	}
	dp_dol[v] += rozm[v];
}

void goradfs(int v, int p) {
	par[v] = p;
	if(p == -1) dp_gora[v] = 1;
	else {
		dp_gora[v] = dp_gora[p] + dp_dol[p] - dp_dol[v] + n - rozm[v] * 2;
	}
	for(auto ch : G[v]) {
		if(ch == p) continue;
		goradfs(ch, v);
	}
}


ll licz(int v) {
	vi ile(n), plec(n / 2 + 1, INF);
	plec[0] = 0;
	for(auto ch : G[v]) ile[rozm[ch]]++;
	FOR(w, 0, n) {
		if(!ile[w]) continue;
		FOR(i, w, n / 2 + 1) plec[i] = min(plec[i], plec[i - w] + 1);
		FOR(i, 0, n / 2 + 1) plec[i] = (plec[i] <= ile[w] ? 0 : INF);
	}
	int heh = (n - 1) / 2;
	while(plec[heh] == INF) heh--;
	return dp_dol[v] + 1ll * heh * (n - 1 - heh);
}

ll f(int cen) {
	rozmdfs(cen, -1);
return licz(cen);
	goradfs(cen, -1);
	ll ans = 0;
	FOR(i, 1, n + 1) {
		ans = max(ans, dp_dol[i] + dp_gora[i] - 1 + (rozm[i] - 1) * (n - rozm[i]));  
	}
	return max(ans, licz(cen));
}

void solve() {
	cin >> n;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		G[a].PB(i + 1);
		G[i + 1].PB(a);
	}
	SZ = szdfs(1, -1);
	CEN.clear();
	szdfs(1, -1);
	// CEN - vector centroidow
	ll ans = 0;
CEN.resize(1);
	for(auto cen : CEN) ans = max(ans, f(cen));
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1; //cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}