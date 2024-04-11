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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 3e5 + 5;
const int mod = 1000000007;

int n;
vector<int> gr[MAXN];
int h[MAXN];
int le[MAXN], ri[MAXN];
int t[2][3 + 4 * MAXN];
int cid = 0;

int dfs(int v, int p = -1){
	h[v] = (p == -1) ? 0 : (1 + h[p]);
	le[v] = cid++;
	ri[v] = le[v];
	I(u, gr[v])if(u != p)ri[v] = max(ri[v], dfs(u, v));
	ret ri[v];
}

void build(int v, int l, int r){
	t[0][v] = t[1][v] = 0;
	if(l == r)ret;
	int mid = (l + r) >> 1;
	build(v + v, l, mid);
	build(v + v + 1, mid + 1, r);
}

void upd(int id, int v, int l, int r, int ul, int ur, int d){
	if(ul > ur)ret;
	if(l == ul && r == ur){
		t[id][v] += d;
		if(t[id][v] >= mod)t[id][v] -= mod;
		ret;
	}
	int mid = (l + r) >> 1;
	upd(id, v + v, l, mid, ul, min(ur, mid), d);
	upd(id, v + v + 1, mid + 1, r, max(ul, mid + 1), ur, d);
}

int get(int id, int v, int l, int r, int pos, int add){
	add += t[id][v];
	if(add >= mod)add -= mod;
	if(l == r)ret add;
	int mid = (l + r) >> 1;
	if(pos <= mid)ret get(id, v + v, l, mid, pos, add);
	else ret get(id, v + v + 1, mid + 1, r, pos, add);
}

int main(){
	scanf("%d", &n);
	build(1, 0, n - 1);
	F(i, 0, n - 1){
		int v = i + 1, u;
		scanf("%d", &u); u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	dfs(0); 
	int q;
	scanf("%d", &q);
	F(i, 0, q){
		int tp, v;
		scanf("%d%d", &tp, &v); v--;
		if(tp == 2){
			lint ans = get(0, 1, 0, n - 1, le[v], 0) - h[v] * 1ll * get(1, 1, 0, n - 1, le[v], 0);
			ans %= mod;
			if(ans < 0)ans += mod;
			printf("%lld\n", ans);
		}
		else{
			int x, k;
			scanf("%d%d", &x, &k);
			upd(0, 1, 0, n - 1, le[v], ri[v], (x + h[v] * 1ll * k)%mod);
			upd(1, 1, 0, n - 1, le[v], ri[v], k);
		}
	}
	ret 0;
}