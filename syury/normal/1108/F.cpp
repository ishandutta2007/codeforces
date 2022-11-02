#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

const int N = (int)2e5 + 5;

struct edge{
	int v, u, w;
	bool operator < (const edge & e)const{return w < e.w;}
};

int n, m;
edge e[N];
int p[N];

int get(int v){
	return v == p[v] ? v : p[v] = get(p[v]);
}

int unite(int v, int u){
	v = get(v); u = get(u);
	if(v == u)
		ret 0;
	p[v] = u;
	ret 1;
}

signed main(){
	sync;
	cin >> n >> m;
	F(i, 0, m){
		cin >> e[i].v >> e[i].u >> e[i].w;
		--e[i].v; --e[i].u;
	}
	sort(e, e + m);
	iota(p, p + n, 0);
	int j = 0;
	int ans = 0;
	while(j < m){
		int k = j;
		while(k < m && e[j].w == e[k].w)
			++k;
		int tot = 0;
		F(i, j, k){
			if(get(e[i].v) != get(e[i].u))
				++tot;
		}
		F(i, j, k)
			if(unite(e[i].v, e[i].u))
				--tot;
		ans += tot;
		j = k;
	}
	cout << ans;
	return 0;
}