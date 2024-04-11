#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val, ans, lazy, lazyn, id;
	Node *c[2], *p;
	Node(int i, int v) {
		val = v;
		ans = lazy = lazyn = 0;
		id = i;
		c[0] = c[1] = p = 0;
	}
};

void push(Node* x) {
	x->val-=x->lazy;
	x->ans+=x->lazyn;
	for (int d=0;d<2;d++) if (x->c[d]) {
		x->c[d]->lazy+=x->lazy;
		x->c[d]->lazyn+=x->lazyn;
	}
	x->lazy = 0;
	x->lazyn = 0;
}
void pull(Node* x) {}

void print(Node* x, int d) {
	if (!x) return;
	push(x);
	for (int i=0;i<d;i++) printf("  ");
	printf("%d %d\n",x->val,x->id);
	print(x->c[0],d+1);
	for (int i=0;i<d;i++) printf("  ");
	printf("-\n");
	print(x->c[1],d+1);
	for (int i=0;i<d;i++) printf("  ");
	printf("-\n");
}
void print(Node* x) {
	printf("PRINTING\n");
	print(x,0);
	printf("\n");
}

void rot(Node* x) {
	Node* p = x->p;
	push(p); push(x);
	if (p->p) {
		int d = p->p->c[1]==p;
		p->p->c[d] = x; x->p = p->p;
	} else x->p = 0;
	int d = p->c[1]==x;
	p->c[d] = x->c[!d]; if (x->c[!d]) x->c[!d]->p = p;
	x->c[!d] = p; p->p = x;
	pull(p); pull(x);
}
void splay(Node* x) {
	while (x->p) {
		Node* p = x->p;
		if (p->p) {
			Node* g = p->p;
			push(g); push(p);
			if ((g->c[1]==p)==(p->c[1]==x)) rot(p);
			else rot(x);
		}
		rot(x);
	}
	push(x);
}

void insert(Node*& x, Node* y) {
	if (x) {
		while (true) {
			push(x);
			int d = x->val<y->val;
			if (x->c[d]) x = x->c[d];
			else {
				x->c[d] = y;
				y->p = x;
				splay(y);
				break;
			}
		}
	}
	x = y;
}

Node* split(Node*& x, int v) {
	insert(x,new Node(0,v));
	Node* y = x;
	x = y->c[0];
	if (x) x->p = 0;
	y = y->c[1];
	if (y) y->p = 0;
	return y;
}
void merge(Node*& x, Node* y) {
	if (!x) {
		x = y;
		return;
	}
	while (x->c[1]) {
		push(x);
		x = x->c[1];
	}
	splay(x);
	x->c[1] = y; if (y) y->p = x;
}

Node* erase(Node*& x) {
	while (x->c[0]) {
		push(x);
		x = x->c[0];
	}
	splay(x);
	Node* y = x;
	x = x->c[1];
	y->c[1] = 0; if (x) x->p = 0;
	return y;
}

#define A first
#define B second

int n,q;
pair<int,int> shirt[200013];
Node* head;
int ans[200013];

bool comp(pair<int,int> a, pair<int,int> b) {
	if (a.B!=b.B) return a.B>b.B;
	return a.A<b.A;
}

void process(Node* x) {
	if (!x) return;
	push(x);
	ans[x->id] = x->ans;
	for (int d=0;d<2;d++) process(x->c[d]);
}

int main() {
	scanf("%d",&q);
	for (int i=0;i<q;i++) scanf("%d%d",&shirt[i].A,&shirt[i].B);
	sort(shirt,shirt+q,comp);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int v;
		scanf("%d",&v);
		insert(head,new Node(i,v));
	}
	for (int i=0;i<q;i++) {
		Node* other = split(head,shirt[i].A);
		if (other) {
			other->lazy+=shirt[i].A;
			other->lazyn+=1;
		}
		while (other) {
			Node* x = erase(other);
			if (x->val>=shirt[i].A) {
				insert(other,x);
				break;
			}
			insert(head,x);
		}
		merge(head,other);
	}
	process(head);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}