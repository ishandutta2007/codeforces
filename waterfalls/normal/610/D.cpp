#include <bits/stdc++.h>
using namespace std;

const int INF = 1.01e9;
typedef long long ll;

int mid(int a, int b) { return a>0 ? (a+b)/2 : (a+b-1)/2; }
struct Node { // because why not. hopefully I don't MLE
	int low, num;
	int lazy;
	Node *c[2];
	Node(int l, int r) {
		low = lazy = 0;
		num = r-l+1;
		c[0] = c[1] = 0;
	}
};
void push(Node* x, int L, int R) {
	if (!x || !x->lazy) return;
	x->low+=x->lazy;
	if (!x->c[0]) x->c[0] = new Node(L,mid(L,R));
	if (!x->c[1]) x->c[1] = new Node(mid(L,R)+1,R);
	for (int d=0;d<2;d++) x->c[d]->lazy+=x->lazy;
	x->lazy = 0;
}
void update(Node*& x, int L, int R, int a, int b, int v) {
	if (!x) x = new Node(L,R);
	push(x,L,R);
	if (b<L || R<a) return;
	if (a<=L && R<=b) {
		x->lazy = v;
		push(x,L,R);
	} else {
		update(x->c[0],L,mid(L,R),a,b,v), update(x->c[1],mid(L,R)+1,R,a,b,v);
		x->low = INF;
		for (int d=0;d<2;d++) if (x->c[d]) x->low = min(x->low,x->c[d]->low);
		x->num = 0;
		for (int d=0;d<2;d++) if (x->c[d] && x->c[d]->low==x->low) x->num+=x->c[d]->num;
	}
}
int query(Node* x, int L, int R) {
	push(x,L,R);
	return 2*INF+1-x->num;
}

struct Event {
	int x,a,b,v;
	bool operator<(Event o) const { return x<o.x; }
};

int n;
vector<Event> events;

int main() {
	Node* head = new Node(-INF,INF);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		events.push_back({x1,y1,y2,1});
		events.push_back({x2+1,y1,y2,-1});
	}
	sort(events.begin(),events.end());
	ll ans = 0;
	int prev = -INF;
	for (auto e: events) {
		ans+=(ll) query(head,-INF,INF)*(e.x-prev);
		prev = e.x;
		update(head,-INF,INF,e.a,e.b,e.v);
	}
	printf("%lld\n",ans);

	return 0;
}