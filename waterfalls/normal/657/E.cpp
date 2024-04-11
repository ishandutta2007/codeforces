#include <bits/stdc++.h>
using namespace std;

struct Node {
	int valb, valt;
	int stsb, stst;
	bool rev;
	int lazy;
	Node *c[2], *p;
	Node(bool v) {
		valb = valt = stsb = stst = v;
		rev = 0;
		lazy = 0;
		c[0] = c[1] = p = 0;
	}
};

void push(Node* x) {
	if (!x) return;
	if (x->lazy) {
		x->valb = x->valt*(2-x->lazy);
		x->stsb = x->stst*(2-x->lazy);
		for (int d=0;d<2;d++) if (x->c[d]) x->c[d]->lazy = x->lazy;
		x->lazy = 0;
	}
	if (x->rev) {
		swap(x->c[0],x->c[1]);
		for (int d=0;d<2;d++) if (x->c[d]) x->c[d]->rev^=x->rev;
		x->rev = 0;
	}
}
void calc(Node* x) {
	if (!x) return;
	for (int d=0;d<2;d++) if (x->c[d]) push(x->c[d]);
	x->stst = x->valt;
	for (int d=0;d<2;d++) if (x->c[d]) x->stst+=x->c[d]->stst;
	x->stsb = x->valb;
	for (int d=0;d<2;d++) if (x->c[d]) x->stsb+=x->c[d]->stsb;
}

bool isroot(Node* x) { return !x->p || (x->p->c[0]!=x && x->p->c[1]!=x); }
void rot(Node* x) {
	Node* p = x->p;
	if (!isroot(p)) {
		push(p->p); push(p);
		int d = p->p->c[1]==p;
		p->p->c[d] = x; x->p = p->p;
	} else x->p = p->p;
	push(p); push(x);
	int d = p->c[1]==x;
	p->c[d] = x->c[!d]; if (x->c[!d]) x->c[!d]->p = p;
	x->c[!d] = p; p->p = x;
	calc(p); calc(x);
}
void splay(Node* x) {
	while (!isroot(x)) {
		Node* p = x->p;
		if (!isroot(p)) {
			Node* g = p->p;
			push(g); push(p);
			if ((g->c[1]==p)==(p->c[1]==x)) rot(p);
			else rot(x);
		}
		rot(x);
	}
	push(x);
}

void expose(Node* x) {
	Node* p = x;
	Node* l = 0;
	while (true) {
		splay(x);
		x->c[0] = l;
		calc(x);
		l = x;
		if (x->p) x = x->p;
		else break;
	}
	splay(p);
}

void evert(Node* x) {
	expose(x);
	x->rev^=1;
	push(x);
}

void link(Node* x, Node* y) {
	evert(x); expose(y);
	x->p = y;
}
void cut(Node* x, Node* y) {
	evert(y); expose(x);
	x->c[1] = 0; y->p = 0;
	calc(x);
}

bool path(Node* x, Node* y) {
	evert(y); expose(x);
	return !x->stsb;
}

void update(Node* x, Node* y, bool on) {
	evert(y); expose(x);
	x->lazy = on+1; push(x);
}

bool conn(Node* x, Node* y) {
	expose(x); expose(y);
	return x==y || x->p;
}

int n,m,q;
vector<int> adj[300013];
int which[300013], up[300013];
Node* nodes[900013];

int n1,m1;
int x1[300013];
int a1[300013], b1[300013];
int bad[300013];

int counter = 0;
int num[300013], low[300013];
stack<int> bcc;
void dfs(int x, int p=0) {
	num[x] = low[x] = ++counter;
	bcc.push(x);
	for (int i: adj[x]) {
		if (i==p) p = 0;
		else if (!num[i]) {
			dfs(i,x);
			if (low[i]>num[x]) {
				while (num[bcc.top()]>=num[i]) {
					which[bcc.top()] = i;
					bcc.pop();
				}
				up[i] = x;
			}
			low[x] = min(low[x],low[i]);
		} else low[x] = min(low[x],num[i]);
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
	}
	for (int i=1;i<=n;i++) adj[0].push_back(i);
	dfs(0);
	for (int i=1;i<=n;i++) if (which[i]==i) nodes[i] = new Node(0);
	int on = n;
	for (int i=1;i<=n;i++) if (up[i]) {
		nodes[++on] = new Node(1);
		link(nodes[which[i]],nodes[on]);
		link(nodes[which[up[i]]],nodes[on]);
	}
	int res = 0;
	for (int num=1;num<=q;num++) {
		scanf("%d%d",&n1,&m1);
		for (int i=0;i<n1;i++) {
			scanf("%d",&x1[i]);
			x1[i] = which[(x1[i]-1+res+n)%n+1];
		}
		for (int i=0;i<m1;i++) {
			scanf("%d%d",&a1[i],&b1[i]);
			a1[i] = which[(a1[i]-1+res+n)%n+1];
			b1[i] = which[(b1[i]-1+res+n)%n+1];
			Node *a = nodes[a1[i]], *b = nodes[b1[i]];
			bad[i] = 0;
			if (!conn(a,b)) {
				nodes[++on] = new Node(1);
				link(a,nodes[on]);
				link(b,nodes[on]);
				bad[i] = on;
			} else update(a,b,1);
		}
		bool ok = 1;
		for (int i=1;i<n1;i++) {
			ok&=conn(nodes[x1[0]],nodes[x1[i]]);
			ok&=path(nodes[x1[0]],nodes[x1[i]]);
		}
		for (int i=m1-1;i>=0;i--) {
			Node *a = nodes[a1[i]], *b = nodes[b1[i]];
			if (bad[i]) {
				cut(a,nodes[bad[i]]);
				cut(b,nodes[bad[i]]);
			} else update(a,b,0);
		}
		printf("%s\n",ok ? "YES" : "NO");
		res = (res+ok*num)%n;
	}

	return 0;
}