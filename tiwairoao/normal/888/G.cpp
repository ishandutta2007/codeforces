#include<map>
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int MAXN = 200000;
struct Trie{
	struct node{
		int cnt, pos;
		node *ch[2];
	}pl[35*MAXN + 5], *ncnt, *root;
	Trie() {ncnt = root = &pl[0];}
	void update(node *x, int k, int dep, int del, int ps) {
		x->cnt += del, x->pos = ps;
		if( dep == -1 ) return ;
		int t = (k >> dep) & 1;
		if( !x->ch[t] ) x->ch[t] = (++ncnt);
		update(x->ch[t], k, dep - 1, del, ps);
	}
	void update(int x, int ps, int del) {update(root, x, 29, del, ps);}
	int query(node *x, int k, int dep) {
		if( dep == -1 ) return x->pos;
		int t = (k >> dep) & 1;
		if( x->ch[t] && x->ch[t]->cnt )
			return query(x->ch[t], k, dep - 1);
		else return query(x->ch[!t], k, dep - 1);
	}
	int query(int x) {return query(root, x, 29);}
}T;
map<int, int>mp;
int a[MAXN + 5], fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) {
		fa[fx] = fy;
		return true;
	}
	else return false;
}
int clr[MAXN + 5], lnk[MAXN + 5], mn[MAXN + 5];
vector<int>v[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]), T.update(a[i], i, 1);
		if( mp.count(a[i]) ) fa[i] = mp[a[i]];
		else fa[i] = i;
		mp[a[i]] = i;
	}
	long long ans = 0;
	while( true ) {
		int cnt = 0;
		for(int i=1;i<=n;i++)
			if( fa[i] == i ) clr[i] = (++cnt);
		if( cnt == 1 ) break;
		for(int i=1;i<=n;i++)
			v[clr[find(i)]].push_back(i);
		for(int i=1;i<=cnt;i++) {
			for(int j=0;j<v[i].size();j++)
				T.update(a[v[i][j]], v[i][j], -1);
			mn[i] = -1;
			for(int j=0;j<v[i].size();j++) {
				int x = v[i][j], p = T.query(a[x]);
				if( mn[i] == -1 || mn[i] > (a[x]^a[p]) )
					lnk[i] = p, mn[i] = a[x]^a[p];
			}
			for(int j=0;j<v[i].size();j++)
				T.update(a[v[i][j]], v[i][j], 1);
			v[i].clear();
		}
		for(int i=1;i<=n;i++)
			if( fa[i] == i )
				if( unite(i, lnk[clr[i]]) )
					ans += mn[clr[i]];
	}
	printf("%lld\n", ans);
}