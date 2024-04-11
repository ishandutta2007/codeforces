#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	int val;
	Node* c[2];
	Node() {
		val = 0;
		c[0] = c[1] = 0;
	}
};

void update(Node*& x, int on, int a) {
	if (!x) x = new Node();
	x->val+=1;
	if (on==-1) return;
	update(x->c[(a&(1<<on))>0],on-1,a);
}

int query(Node* x, int on, int a, int k) {
	if (!x) return 0;
	if (on==-1) return x->val;
	int res = 0;
	if (!(k&(1<<on)) && x->c[!(a&(1<<on))]) res+=x->c[!(a&(1<<on))]->val;
	return res+query(x->c[((k^a)&(1<<on))>0],on-1,a,k);
}

int n,k;
Node* head;

int main() {
	head = new Node();
	scanf("%d%d",&n,&k);
	ll ans = 0;
	int prev = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		update(head,29,prev);
		prev^=x;
		ans+=query(head,29,prev,k);
	}
	printf("%lld\n",ans);

	return 0;
}