#include <bits/stdc++.h>

typedef long long ll;

const int N = 500000;

std::vector<int>v[N + 5];
int tim[N + 5]; ll sum[N + 5];

int fa[N + 5], siz[N + 5];
int find(int x) {return (fa[x] == x ? x : find(fa[x]));}
bool unite(int x, int y, int t) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) {
		if( siz[fx] < siz[fy] ) std::swap(fx, fy);
		fa[fy] = fx, tim[fy] = t, siz[fx] += siz[fy], sum[fy] -= sum[fx];
		return true;
	} else return false;
}
int get1(int x) {
	int ret = 0, mxt = 0;
	while( true ) {
		if( !v[x].empty() && v[x].back() > mxt )
			ret = std::max(ret, v[x].back());
		if( fa[x] == x ) break;
		else mxt = std::max(mxt, tim[x]), x = fa[x];
	};
	return ret;
}
ll get2(int x) {
	ll ret = 0;
	while( true ) {
		ret += sum[x];
		if( fa[x] == x ) break;
		else x = fa[x];
	}
	return ret;
}

struct query{
	char op; int x, y;
}a[N + 5]; int n, m;

ll ans[N + 5]; std::vector<int>qry[N + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1,x,y;i<=m;i++) {
		char op[2]; scanf("%s%d", op, &x);
		if( op[0] == 'U' || op[0] == 'M' )
			scanf("%d", &y);
		else y = 0;
		a[i] = (query){op[0], x, y};
	}
	
	for(int i=1;i<=n;i++) fa[i] = i, siz[i] = 1, v[i].clear(), sum[i] = 0, tim[i] = 0;
	for(int i=1;i<=m;i++) {
		if( a[i].op == 'M' ) unite(a[i].x, a[i].y, i);
		else if( a[i].op == 'Z' ) v[find(a[i].x)].push_back(i);
		else if( a[i].op == 'Q' ) qry[get1(a[i].x)].push_back(i);
	}
	
	for(int i=1;i<=n;i++) fa[i] = i, siz[i] = 1, v[i].clear(), sum[i] = 0, tim[i] = 0;
	for(int i=1;i<=m;i++) {
		if( a[i].op == 'U' ) unite(a[i].x, a[i].y, i);
		else if( a[i].op == 'A' ) sum[find(a[i].x)] += siz[find(a[i].x)];
		else if( a[i].op == 'Q' ) ans[i] += get2(a[i].x);
		
		for(auto x : qry[i])
			ans[x] -= get2(a[x].x);
	}
	for(int i=1;i<=m;i++) if( a[i].op == 'Q' ) printf("%lld\n", ans[i]);
}