#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm afhdhn

const lint mod = 1000000007;
const int MAXN = 2e5 + 5;

lint gcdex(lint a, lint b, lint & x, lint & y){
	if(a == 0){
		x = 0; y = 1;
		ret b;
	}
	lint x1, y1;
	lint g = gcdex(b % a, a, x1, y1);
	y = x1;
	x = y1 - (b/a) * x1;
	ret g;
}

lint inv(lint a){
	lint x, y;
	gcdex(a, mod, x, y);
	x %= mod;
	ret (x + mod)%mod;
}

int n;
vector<list<int> > gr;
vector<lint> dp, ans;
vector<vector<int> > dcpl, dcpr, tmul;
int sz = 0;

void dfs0(int v, int p = -1){
	dp[v] = 1ll;
	I(u, gr[v]){
		if(u == p)cont;
		dfs0(u, v);
		dp[v] = dp[v] * (dp[u] + 1) % mod;
	}
	ans[v] = dp[v];
}

void dfs1(int v, int p = -1, lint mul = 1ll){
	ans[v] = (ans[v] * mul) % mod;
	lint mul1 = 1ll, mul2 = 1ll;
	sz = 0;
	dcpl[v].rs(gr[v].size());
	dcpr[v].rs(gr[v].size());
	tmul[v].rs(gr[v].size());
	F(it, gr[v].begin(), gr[v].end()){
		int u = *it;
		if(u == p)cont;
		mul1 = mul1 * (dp[u] + 1) % mod;
		dcpl[v][sz++] = mul1;
	}
	int ptr = sz - 1;
	auto it = gr[v].end(); it--;
	while(true){
		int u = *it;
		if(u != p){
			mul2 = mul2 * (dp[u] + 1) % mod;
			dcpr[v][ptr--] = mul2;
		}
		if(it == gr[v].begin())brk;
		it--;
	}
	int pref = 0;
	I(u, gr[v]){
		if(u == p)cont;
		lint fmul = ((pref == 0) ? 1ll : dcpl[v][pref - 1]) * ((pref == sz - 1) ? 1ll : dcpr[v][pref + 1]);
		tmul[v][pref] = fmul % mod;
		
		pref++;
	}
	pref = 0;
	I(u, gr[v]){
		if(u == p)cont;
		dfs1(u, v, (1 + mul * tmul[v][pref]) % mod);
		pref++;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	gr.rs(n); dp.rs(n); ans.rs(n);
	dcpl.rs(n); dcpr.rs(n); tmul.rs(n);
	F(i, 0, n - 1){
		int u;
		scanf("%d", &u); u--;
		gr[u].pb(i + 1);
		gr[i + 1].pb(u);
	}
	dfs0(0);
	dfs1(0);
	F(i, 0, n){
		printf("%lld ", ans[i]);
	}
	ret 0;
}