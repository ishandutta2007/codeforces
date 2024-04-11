#include<bits/stdc++.h>

const int N = 100010;
const int moder = 1e9 + 7;

int fa[N << 1];
int deg[N << 1];
int x[N], y[N], xx[N], yy[N];
std::vector <int> vec[N << 1];

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int find(int u){
	return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u != _v) fa[_u] = _v;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &x[i], &y[i]);
		xx[i] = x[i];
		yy[i] = y[i];
	}
	std::sort(xx, xx + n);
	std::sort(yy, yy + n);
	int cntx = std::unique(xx, xx + n) - xx;
	int cnty = std::unique(yy, yy + n) - yy;
	for (int i = 0; i < cntx + cnty; ++ i){
		fa[i] = i;
	}
	for (int i = 0; i < n; ++ i){
		int sitx = std::lower_bound(xx, xx + cntx, x[i]) - xx;
		int sity = std::lower_bound(yy, yy + cnty, y[i]) - yy;
		unite(sitx, cntx + sity);
		++ deg[sitx];
		++ deg[cntx + sity];
	}
	for (int i = 0; i < cntx + cnty; ++ i){
		find(i);
		vec[fa[i]].push_back(i);
	}
	int ans = 1;
	for (int i = 0; i < cntx + cnty; ++ i){
		if (vec[i].empty()) continue;
		int cnt = 0;
		for (auto u : vec[i]){
			cnt += deg[u];
		}
		int sz = vec[i].size();
		int tmp = powermod(2, sz);
		if (cnt < sz << 1){
			tmp = (tmp - 1 + moder) % moder;
		}
		ans = 1ll * ans * tmp % moder;
	}
	return printf("%d\n", ans), 0;
}