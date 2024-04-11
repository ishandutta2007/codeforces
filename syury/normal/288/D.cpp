#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = 1e5 + 5;

ull t[maxn];
int id[maxn];
vector<int> gr[maxn];
ull sz[maxn];
int cid = 0;
int n;
ull tot = 0;

void add(int v, ull val){
	while(v <= n){
		t[v] += val;
		v += v&-v;
	}
}

ull get(int pref){
	ull ans = 0;
	while(pref){
		ans += t[pref];
		pref -= pref&-pref;
	}
	ret ans;
}

void prepare(int v, int p = -1){
	sz[v] = 1;
	id[v] = cid++;
	I(u, gr[v]){
		if(u != p){
			prepare(u, v);
			sz[v] += sz[u];
		}
	}
}

void dfs(int v, int p = -1, ull carry = 0){
	ull cnt = 0;
	I(u, gr[v]){
		if(u == p)cont;
		cnt += sz[u] * (sz[v] - sz[u]);
	}
	cnt += sz[v] - 1;
	cnt /= 2;
	//cout << v << " " << cnt << endl;
	add(id[v] + 1, cnt);
	ull cu = get(id[v]);
	cu -= carry * sz[v];
	//cout << v << " " << cu << endl;
	tot += cu * cnt;
	I(u, gr[v]){
		if(u == p)cont;
		dfs(u, v, carry + (sz[v] - sz[u]));
	}
}

int main() {
    sync;
	cin >> n;
	F(i, 0, n - 1){
		int v, u;
		cin >> v >> u;
		--v; --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	prepare(0);
	dfs(0);
	cout << 2*tot;
}