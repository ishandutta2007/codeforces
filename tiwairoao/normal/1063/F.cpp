#include <bits/stdc++.h>

const int N = 1000000;

int ch[26][N + 5], fa[N + 5], len[N + 5], ncnt, lst, rt;
void extend(int c) {
	int cur = (++ncnt), p = lst; len[cur] = len[lst] + 1, lst = cur;
	while( p && !ch[c][p] ) ch[c][p] = cur, p = fa[p];
	
	if( !p ) fa[cur] = rt;
	else {
		int q = ch[c][p];
		if( len[p] + 1 == len[q] ) fa[cur] = q;
		else {
			int nq = (++ncnt); fa[nq] = fa[q], len[nq] = len[p] + 1;
			for(int i=0;i<26;i++) ch[i][nq] = ch[i][q];
			fa[q] = fa[cur] = nq;
			
			while( p && ch[c][p] == q ) ch[c][p] = nq, p = fa[p];
		}
	}
}

struct node{int x, l;};
node nxt(const node &k, int c) {return (node){ch[c][k.x], k.l + 1};}
node fat(const node &k) {
	if( k.l - 1 == len[fa[k.x]] ) return (node){fa[k.x], k.l - 1};
	else return (node){k.x, k.l - 1};
}

std::vector<int>v[N + 5];

int dl[N + 5], dr[N + 5], dcnt;
void dfs(int x) {
	dl[x] = (++dcnt);
	for(unsigned i=0;i<v[x].size();i++) dfs(v[x][i]);
	dr[x] = dcnt;
}

int tree[N + 5];
void add(int x, int k) {
	for(int i=x;i<=dcnt;i+=i&(-i)) tree[i] += k;
}
int sum(int x) {
	int r = 0; for(int i=x;i;i-=i&(-i)) r += tree[i]; return r;
}

int val[N + 5];
bool check(const node &k) {
	return val[k.x] >= k.l || sum(dr[k.x]) - sum(dl[k.x]);
}
void update(const node &k) {
	val[k.x] = std::max(val[k.x], k.l), add(dl[k.x], 1);
}

node g[N + 5]; int f[N + 5], n;

char s[N + 5];
int main() {
	scanf("%d", &n), scanf("%s", s);
	lst = rt = ncnt = 1; for(int i=n-1;i>=0;i--) extend(s[i] - 'a');
	for(int i=2;i<=ncnt;i++) v[fa[i]].push_back(i); dfs(rt);
	
	node p = (node){rt, 0};
	for(int l=n-1,r=n-1;l>=0;l--) {
		node q = p; p = nxt(p, s[l] - 'a');
		while( l < r && !check(q) && !check(fat(p)) )
			p = fat(p), q = fat(q), update(g[r--]);
		g[l] = p, f[l] = r - l + 1;
	}
	
	printf("%d\n", *std::max_element(f, f + n));
}