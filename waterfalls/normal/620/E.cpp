#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class ST {
private:
	int size;
	ll st[1<<20], lazy[1<<20];
	void push(int w, int L, int R) {
		if (lazy[w]) {
			st[w] = lazy[w];
			if (L!=R) lazy[w*2] = lazy[w*2+1] = lazy[w];
		}
		lazy[w] = 0;
	}
	void updateI(int w, int L, int R, int a, int b, ll c) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) lazy[w] = c, push(w,L,R);
		else {
			updateI(w*2,L,(L+R)/2,a,b,c), updateI(w*2+1,(L+R)/2+1,R,a,b,c);
			st[w] = st[w*2]|st[w*2+1];
		}
	}
	ll queryI(int w, int L, int R, int a, int b) {
		push(w,L,R);
		if (b<L || R<a) return 0;
		if (a<=L && R<=b) return st[w];
		return queryI(w*2,L,(L+R)/2,a,b)|queryI(w*2+1,(L+R)/2+1,R,a,b);
	}
public:
	ST(int s=0) {
		size = s;
		fill(st,st+(1<<20),0);
		fill(lazy,lazy+(1<<20),0);
	}
	void update(int a, int b, ll c) { updateI(1,1,size,a,b,c); }
	int query(int a, int b) { return __builtin_popcountll(queryI(1,1,size,a,b)); }
};

int n,m;
int c[400013];
vector<int> adj[400013];
ST tree;
int counter = 0;
int s[400013], e[400013];

void dfs(int x, int p=0) {
	s[x] = ++counter;
	tree.update(s[x],n,1LL<<c[x]);
	for (int i: adj[x]) if (i!=p) dfs(i,x);
	e[x] = counter;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=0;i<n-1;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	tree = ST(n);
	dfs(1);
	for (int i=0;i<m;i++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			int v,c;
			scanf("%d%d",&v,&c);
			tree.update(s[v],e[v],1LL<<c);
		} else {
			int v;
			scanf("%d",&v);
			printf("%d\n",tree.query(s[v],e[v]));
		}
	}

	return 0;
}