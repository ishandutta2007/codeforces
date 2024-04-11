//#pragma GCC optimize ("O3") 

#include <stdio.h>
#include <bits/stdc++.h>

#define F first
#define S second
#define elif else if

#define INV(x) inv(x, MOD)
#define ADD(a, b) (((ll)(a)+(b))%MOD)
#define SUB(a, b) (((ll)(a)-(b))%MOD)
#define MUL(a, b) (((ll)(a)*(b))%MOD)
#define DIV(a, b) (((ll)(a)*INV(b))%MOD)

using namespace std;
using ll = long long;
using ld = double;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;

const int N = 2e5+7;

bool bad[N];
int n, k, a[N], z[N], p[N], res[N], maxc=1;
vector<pii> mv[N];

void dfs(int v, int p = -1) {
	int colorin = p == -1 ? -1 : a[v];
	if(bad[v] && colorin == -1) colorin = 1;
	int colorto = 1;

	for(auto to : mv[v]) {
		if(to.F == p) continue;

		if(bad[v]) a[to.F] = colorin;	
		else {
			if(colorin == colorto) ++colorto;
			maxc = max(maxc, colorto);
			a[to.F] = colorto++;
		}
		res[to.S] = a[to.F]; dfs(to.F, v);
	}
}

void solve(bool debug) {
	int n, k; cin >> n >> k;
	for(int i = 1; i < n; ++i) {
		int a,b; cin >> a >> b;
		mv[a-1].push_back({ b-1, i }); ++z[a-1];
		mv[b-1].push_back({ a-1, i }); ++z[b-1];
	}

	iota(p, p+n, 0);
	sort(p, p+n, [](int i, int j) {
		return z[i] > z[j];
	});

	for(int i = 0; i < k; ++i) bad[p[i]] = true;
	dfs(0);
	cout << maxc << endl;
	for(int i = 1; i < n; ++i)
		cout << res[i] << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve(0);
}