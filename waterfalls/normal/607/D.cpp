#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
int add(int a, int b) { return a+b-MOD*(a+b>=MOD); }
int sub(int a, int b) { return a-b+MOD*(a-b<0); }
int mult(int a, int b) { return ((ll) a*b)%MOD; }
int inv(int x) {
	int p = MOD-2;
	int i = 0;
	int res = 1;
	while (p) {
		if (p&1) res = mult(res,x);
		i+=1; p>>=1;
		x = mult(x,x);
	}
	return res;
}

class ST {
private:
	int size;
	int st[1<<19], prod[1<<19];
	void updateI(int w, int L, int R, int a, int b, int v) {
		if (b<L || R<a) return;
		if (a<=L && R<=b) {
			prod[w] = mult(prod[w],v);
			st[w] = mult(st[w],v);
		} else {
			updateI(w*2,L,(L+R)/2,a,b,v), updateI(w*2+1,(L+R)/2+1,R,a,b,v);
			st[w] = mult(prod[w],add(st[w*2],st[w*2+1]));
		}
	}
	void updateI(int w, int L, int R, int a, int v) {
		if (a<L || R<a) return;
		if (L==R) st[w] = mult(prod[w],v);
		else {
			updateI(w*2,L,(L+R)/2,a,v), updateI(w*2+1,(L+R)/2+1,R,a,v);
			st[w] = mult(prod[w],add(st[w*2],st[w*2+1]));
		}
	}
	int queryI(int w, int L, int R, int a, int b) {
		if (b<L || R<a) return 0;
		if (a<=L && R<=b) return st[w];
		return mult(prod[w],add(queryI(w*2,L,(L+R)/2,a,b),queryI(w*2+1,(L+R)/2+1,R,a,b)));
	}
	int queryI(int w, int L, int R, int a) {
		if (a<L || R<a) return 1;
		if (L==R) return prod[w];
		return mult(prod[w],mult(queryI(w*2,L,(L+R)/2,a),queryI(w*2+1,(L+R)/2+1,R,a)));
	}
public:
	ST(int s=0) {
		size = s;
		fill(st,st+(1<<19),0);
		fill(prod,prod+(1<<19),1);
	}
	void update(int a, int b, int v) { updateI(1,1,size,a,b,v); }
	void update(int a, int v) { updateI(1,1,size,a,v); }
	int query(int a, int b) { return queryI(1,1,size,a,b); }
	int query(int a) { return queryI(1,1,size,a); }
};

int n = 0, q;
vector<int> adj[200013];
int p[200013], val[200013];

int s[200013], e[200013];
ST tree;

int type[200013];
int qu[200013];

int child[200013];

int counter;
void setup(int x) {
	s[x] = ++counter;
	child[x] = 1;
	for (int i: adj[x]) setup(i);
	e[x] = counter;
}

int main() {
	n+=1;
	scanf("%d%d",&val[n],&q);
	for (int i=0;i<q;i++) {
		scanf("%d",&type[i]);
		if (type[i]==1) {
			n+=1;
			qu[i] = n;
			scanf("%d%d",&p[n],&val[n]);
			adj[p[n]].push_back(n);
		} else scanf("%d",&qu[i]);
	}
	counter = 0;
	setup(1);
	tree = ST(n);
	tree.update(1,val[1]);
	for (int i=0;i<q;i++) {
		if (type[i]==1) {
			tree.update(s[qu[i]],val[qu[i]]);
			tree.update(s[p[qu[i]]],e[p[qu[i]]],inv(child[p[qu[i]]]));
			child[p[qu[i]]]+=1;
			tree.update(s[p[qu[i]]],e[p[qu[i]]],child[p[qu[i]]]);
		} else {
			int res = tree.query(s[qu[i]],e[qu[i]]);
			res = mult(res,inv(tree.query(s[p[qu[i]]])));
			printf("%d\n",res);
		}
	}

	return 0;
}