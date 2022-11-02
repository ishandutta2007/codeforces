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
typedef double dbl;
typedef pair <int, int> pii;

const int maxn = 2e5 + 5;

int pr[maxn];
dbl sum[maxn];
dbl p[maxn];
int n;
vector<int> gr[maxn];

void dfs(int v, int pp = -1){
	pr[v] = pp;
	sum[v] = 0;
	I(u, gr[v]){
		if(u == pp)cont;
		sum[v] += p[u];
		dfs(u, v);
	}
}

int main() {
    sync;
	scanf("%d", &n);
	F(i, 0, n){
		float tmp;
		scanf("%f", &tmp);
		p[i] = tmp;
	}
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		gr[v].pb(u);
		gr[u].pb(v);
	}
	dfs(0);
	int q;
	scanf("%d", &q);
	dbl ans = 0;
	F(i, 1, n)ans += p[pr[i]] * (1 - p[i]);
	ans += 1-p[0];
	F(i, 0, q){
		int v;
		float _np;
		dbl np;
		scanf("%d%f", &v, &_np);
		np = _np;
		if(v == 0){
			ans = ans - gr[0].size() * p[0] + sum[0] * p[0];
			ans = ans - sum[0] * np + np * gr[0].size();
			ans = ans - (1-p[0]) + (1-np);
			p[0] = np;
		}
		else{
			ans = ans - p[pr[v]] * (1 - p[v]);
			ans = ans + p[pr[v]] * (1 - np);
			ans = ans - (gr[v].size() - 1) * p[v];
			ans = ans + (gr[v].size() - 1) * np;
			ans = ans + p[v] * sum[v];
			ans = ans - np * sum[v];
			sum[pr[v]] = sum[pr[v]] - p[v] + np;
			p[v] = np;
		}
		printf("%.6lf\n", (double)ans);
	}
}