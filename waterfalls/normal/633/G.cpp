#include <bits/stdc++.h>
using namespace std;

int n,m,q;
bitset<1000> primes;

bitset<1000> st[1<<18];
int lazy[1<<18];
void push(int w, int L, int R) {
	bitset<1000> shift = st[w]>>(m-lazy[w]);
	st[w] = (st[w]<<lazy[w])|shift;
	if (L!=R) {
		lazy[w*2] = (lazy[w*2]+lazy[w])%m;
		lazy[w*2+1] = (lazy[w*2+1]+lazy[w])%m;
	}
	lazy[w] = 0;
}
void updateI(int w, int L, int R, int a, int b, int v) {
	if (lazy[w]) push(w,L,R);
	if (b<L || R<a) return;
	if (a<=L && R<=b) {
		lazy[w] = v;
		push(w,L,R);
	} else {
		updateI(w*2,L,(L+R)/2,a,b,v), updateI(w*2+1,(L+R)/2+1,R,a,b,v);
		st[w] = st[w*2]|st[w*2+1];
	}
}
bitset<1000> queryI(int w, int L, int R, int a, int b) {
	if (lazy[w]) push(w,L,R);
	if (b<L || R<a) return bitset<1000>();
	if (a<=L && R<=b) return st[w];
	return queryI(w*2,L,(L+R)/2,a,b)|queryI(w*2+1,(L+R)/2+1,R,a,b);
}
void update(int a, int b, int v) { updateI(1,1,n,a,b,v); }
int query(int a, int b) { return (queryI(1,1,n,a,b)&primes).count(); }

vector<int> adj[100013];
int a[100013];

int counter = 0;
int s[100013], e[100013];

void setup(int x, int p=0) {
	s[x] = ++counter;
	update(s[x],s[x],a[x]%m);
	for (int i: adj[x]) if (i!=p) {
		setup(i,x);
	}
	e[x] = counter;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=2;i<m;i++) {
		bool ok = 1;
		for (int j=2;j*j<=i;j++) {
			if (i%j==0) ok = 0;
		}
		primes[i] = ok;
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0;i<(1<<18);i++) st[i].flip(0);
	setup(1);
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			int v,x;
			scanf("%d%d",&v,&x);
			update(s[v],e[v],x%m);
		} else {
			int v;
			scanf("%d",&v);
			printf("%d\n",query(s[v],e[v]));
		}
	}

    return 0;
}