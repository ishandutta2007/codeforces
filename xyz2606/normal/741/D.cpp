#include<bits/stdc++.h>
using namespace std;
const int N(555555), C(22);
vector<int> sons[N];
int siz[N], dep[N], es[N], a[N], fa[N];
void predfs(int v) {
	siz[v] = 1;
	for(int y : sons[v]) {
		dep[y] = dep[v] + 1;
		predfs(y);
		siz[v] += siz[y];
	}
	if(!sons[v].empty()) {
		sort(sons[v].begin(), sons[v].end(), [&](int a, int b){return siz[a] > siz[b];});
		es[v] = sons[v][0];
		sons[v].erase(sons[v].begin());
	}
}
vector<int> modi;
int delta;
int inf(1e9);
int ans[N], mp[1 << C];
void clear() {
	for(int i : modi) {
		mp[i] = -inf;
	}
	delta = 0;
	modi.clear();
}
vector<pair<int, int> > vec;
void dfs(int v, int msk) {
	msk ^= 1 << a[v];
	vec.push_back(make_pair(dep[v], msk));
	for(int y : sons[v]) {
		dfs(y, msk);
	}
	if(es[v]) {
		dfs(es[v], msk);
	}
}
void renew(int posi, int val) {
	mp[posi] = max(mp[posi], val);
	modi.push_back(posi);
}
void calc(int v) {
	for(int y : sons[v]) {
		calc(y);
		clear();
	}
	if(es[v]) {
		calc(es[v]);
		for(int y : sons[v]) {
			vec.clear();
			dfs(y, 0);
			for(auto tmp : vec) {
				//cout << tmp.first << ' ' << tmp.second << endl;
				//cout << ans[v] << endl;
				ans[v] = max(ans[v], tmp.first + mp[tmp.second ^ delta] - 2 * dep[v]);
				for(int i(0); i < C; i++) {
					ans[v] = max(ans[v], tmp.first + mp[tmp.second ^ (1 << i) ^ delta] - 2 * dep[v]);
				}
				//cout << ans[v] << endl;
			}
			for(auto tmp : vec) {
				renew(tmp.second ^ delta, tmp.first);
			}
		}
		//printf("v = %d delta =%d\n", v, delta);
		ans[v] = max(ans[v], mp[delta] - dep[v]);
		for(int i(0); i < C; i++) {
			//cout << mp[delta ^ (1 << i)] << endl;
			ans[v] = max(ans[v], mp[delta ^ (1 << i)] - dep[v]);
		}
	}
	delta ^= 1 << a[v];
	//cout << v << '?' << delta << endl;
	renew((1 << a[v]) ^ delta, dep[v]);
	ans[fa[v]] = max(ans[fa[v]], ans[v]);
}
int main() {
	int n;
	fill(mp, mp + (1 << C), -inf);
	scanf("%d", &n);
	for(int i(2); i <= n; i++) {
		char c[9];
		int x;
		scanf("%d%s", &x, c);
		a[i] = c[0] - 'a';
		fa[i] = x;
		sons[x].push_back(i);
		//printf("%d->%d\n", i, x);
	}
	predfs(1);
	calc(1);
	for(int i(1); i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}