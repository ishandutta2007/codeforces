#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;
typedef long long int ll;
typedef long double dbl;
typedef unsigned long long uli;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i > r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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
#define tm dhgdg

const int MAXN = 1e5 + 5;

vector<int> gr[MAXN];
int a[MAXN];
int odd[MAXN], even[MAXN];
int n;
ll ans;

void dfs(int v, int p, int pw){
	odd[v] = 0; even[v] = 0;
	if(a[v]&pw)odd[v]++;
	else even[v]++;
	int so = 0, se = 0;
	I(u, gr[v]){
		if(u == p)cont;
		dfs(u, v, pw);
		int o = odd[u], e = even[u];
		so += o; se += e;
		if(a[v]&pw){odd[v] += e; even[v] += o;}
		else {odd[v] += o; even[v] += e;}
	}
	ans += odd[v] * 1ll * pw;
	I(u, gr[v]){
		if(u == p)cont;
		so -= odd[u]; se -= even[u];
		if(a[v]&pw){
			ans += odd[u] * 1ll * so * pw;
			ans += even[u] * 1ll * se * pw;
		}
		else{
			ans += odd[u] * 1ll * se * pw;
			ans += even[u] * 1ll * so * pw;
		}
	}
}

void solve(int pw){
	dfs(0, -1, pw);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n)cin >> a[i];
	F(i, 0, n - 1){
		int v, u;
		cin >> v >> u;
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	for(int i = 0; i < 22; i++){
		solve(1<<i);
	}
	cout << ans;
	return 0;
}