#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Node {
	ll top, lazyv;
	int bot,lazyn;
	Node *c[2], *p;
	Node(ll a=-INF, int b=1) {
		top = a, bot = b;
		lazyv = lazyn = 0;
		c[0] = c[1] = p = 0;
	}
};

bool isroot(Node* x) { return !x->p; }

void push(Node* x) {
	if (!x) return;
	x->top+=x->lazyv;
	x->bot+=x->lazyn;
	for (int d=0;d<2;d++) if (x->c[d]) {
		x->c[d]->lazyv+=x->lazyv;
		x->c[d]->lazyn+=x->lazyn;
	}
	x->lazyv = x->lazyn = 0;
}

void rot(Node* x) {
	Node* p = x->p;
	push(p); push(x);
	if (!isroot(p)) {
		int d = p->p->c[1]==p;
		p->p->c[d] = x; x->p = p->p;
	} else x->p = p->p;
	int d = p->c[1]==x;
	p->c[d] = x->c[!d]; if (x->c[!d]) x->c[!d]->p = p;
	x->c[!d] = p; p->p = x;
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

Node* find(Node* x, ll a) {
	if (!x) return 0;
	push(x);
	if (x->top==a*x->bot) return x;
	if (x->top>a*x->bot) return find(x->c[1],a);
	if (x->top<a*x->bot) {
		Node* cur = find(x->c[0],a);
		return cur ? cur : x;
	}
}

void update(Node* x, ll v) {
	if (!x) return;
	x->lazyv+=v;
	x->lazyn+=1;
}

void inorder(Node* x, vector<ll>& dest) {
    if (!x) return;
    push(x);
    inorder(x->c[0],dest);
    dest.push_back(x->top);
    inorder(x->c[1],dest);
}

int n;
Node* head;

int main() {
	head = new Node();
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		ll a;
		scanf("%lld",&a);
		head = find(head,a);
		splay(head);
		Node* next = new Node(a*head->bot,head->bot);
		next->c[0] = head->c[0]; if (head->c[0]) head->c[0]->p = next;
		head->c[0] = 0;
		next->c[1] = head; head->p = next;
		head = next;
		update(head->c[1],a);
	}
	vector<ll> res;
	inorder(head,res);
	ll ans = 0;
	ll cur = 0;
	for (ll i: res) {
		cur+=i;
		ans = max(ans,cur);
	}
	printf("%lld\n",ans);

	return 0;
}