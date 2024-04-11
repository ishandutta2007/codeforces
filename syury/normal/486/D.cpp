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

const int MAXN = 2e3 + 5;
const lint mod = 1000000007;

int n, d;
int a[MAXN];
lint dp[2][MAXN];
lint ans = 0ll;
vector<list<int> > gr;
int gc;

void dfs(int v, int p = -1){
	if(a[v] == gc)dp[0][v] = 1;
	if(a[v] > gc && a[v] <= gc + d)dp[1][v] = 1;
	I(u, gr[v]){
		if(u == p)cont;
		dfs(u, v);
		dp[0][v] = dp[0][v] * (1 + dp[0][u] + dp[1][u]) % mod;
		dp[0][v] = (dp[0][v] + dp[1][v] * dp[0][u]) % mod;
		dp[1][v] = dp[1][v] * (1 + dp[1][u]) % mod;
	}
	//dp[0][v] -= dp[1][v];
	//if(dp[0][v] < 0)dp[0][v] += mod;
	ans += dp[0][v];
	if(ans > mod)ans -= mod;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &d, &n);
	F(i, 0, n){
		scanf("%d", &a[i]);
	}
	gr.rs(n);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	F(c, 1, 2001){
		gc = c;
		fi0(dp);
		dfs(0);
	}
	printf("%lld", ans);
	ret 0;
}