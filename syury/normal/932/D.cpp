#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned long long ull;
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
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg
#define link kekekeke

const int maxn = 4e5 + 5;
const int lg = 21;

int up[maxn][lg];
int mx[maxn][lg];
ll sum[maxn][lg];
int cnt[maxn][lg];
int w[maxn];
int nextvertex[maxn][lg];

void add(int v, int p, int cw){
	w[v] = cw;
	up[v][0] = p;
	F(i, 1, lg)up[v][i] = up[up[v][i - 1]][i - 1];
	mx[v][0] = w[p];
	F(i, 1, lg)mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
	int u = v;
	DF(i, lg - 1, -1){
		if(mx[u][i] < w[v])u = up[u][i];
	}
	if(u == up[u][0]){
		F(i, 0, lg){nextvertex[v][i] = -1;}
		ret;
	}
	u = up[u][0];
	if(w[u] < w[v]){
		F(i, 0, lg){nextvertex[v][i] = -1;}
		ret;
	}
	nextvertex[v][0] = u;
	sum[v][0] = w[u]; cnt[v][0] = 1;
	F(i, 1, lg){
		u = nextvertex[v][i - 1];
		if(u == -1 || nextvertex[u][i - 1] == -1){nextvertex[v][i] = -1; cont;}
		sum[v][i] = sum[v][i - 1] + sum[u][i - 1];
		nextvertex[v][i] = nextvertex[u][i - 1];
		cnt[v][i] = cnt[v][i - 1] + cnt[u][i - 1];
	}
}

void init(){
	w[0] = 0;
	up[0][0] = 0; mx[0][0] = 0;
	F(i, 1, lg){mx[0][0] = up[0][0] = 0;}
	F(i, 0, lg)nextvertex[0][i] = -1;
}

int solve(int v, ll s){
	s -= w[v];
	int ans = 1;
	if(s < 0)ret 0;
	DF(i, lg - 1, -1){
		if(nextvertex[v][i] != -1 && s >= sum[v][i]){ans += 1<<i; s -= sum[v][i]; v = nextvertex[v][i];}
	}
	ret ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	ll la = 0;
	init();
	int cnt = 1;
	F(i, 0, q){
		int t;
		ll x, y;
		cin >> t >> x >> y;
		int p = x^la;
		ll w = y^la;
		if(t == 1)add(cnt++, p - 1, w);
		else{la = solve(p - 1, w); cout << la << '\n';}
	}
	return 0;
}