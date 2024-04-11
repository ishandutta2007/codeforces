#include<cstdio>
const int MAXN = 300000*45;
struct node{
	node *ch[2];
	int sum, clr;
}tree[MAXN + 5], *tcnt, *root, *NIL;
node *Newnode() {
	tcnt++;
	tcnt->ch[0] = NIL, tcnt->ch[1] = NIL;
	return tcnt;
}
int n, q;
void Init() {
	tcnt = root = NIL = &tree[0];
	NIL->ch[0] = NIL->ch[1] = NIL;
	NIL->sum = 0, NIL->clr = -1;
	root = Newnode();
}
void PushUp(node *x) {
	x->sum = x->ch[0]->sum + x->ch[1]->sum;
	if( x->ch[0]->clr == x->ch[1]->clr && x->ch[0]->clr != -1 )
		x->clr = x->ch[0]->clr;
	else x->clr = -1;
}
void PushDown(node *x, int l, int r) {
	if( x->clr == -1 ) return ;
	if( x->ch[0] == NIL ) {
		x->ch[0] = Newnode();
		x->ch[1] = Newnode();
	}
	if( x->clr == 0 ) {
		x->ch[0]->sum = x->ch[1]->sum = 0;
		x->ch[0]->clr = x->ch[1]->clr = 0;
	}
	if( x->clr == 1 ) {
		int mid = (l + r) >> 1;
		x->ch[0]->sum = (mid-l+1);
		x->ch[1]->sum = (r-mid);
		x->ch[0]->clr = x->ch[1]->clr = 1;
	}
}
void Modify(node *rt, int l, int r, int ml, int mr, int k) {
	if( ml > r || mr < l )
		return ;
	int mid = (l + r) >> 1;
	if( ml <= l && r <= mr ) {
		if( k == 0 ) {
			rt->clr = k;
			rt->sum = 0;
		}
		else {
			rt->clr = k;
			rt->sum = r-l+1;
		}
		return ;
	}
	PushDown(rt, l, r);
	Modify(rt->ch[0], l, mid, ml, mr, k);
	Modify(rt->ch[1], mid+1, r, ml, mr, k);
	PushUp(rt);
}
int main() {
	Init();
	scanf("%d%d", &n, &q);
	root->sum = n; root->clr = 1;
	for(int i=1;i<=q;i++) {
		int k, l, r;
		scanf("%d%d%d", &l, &r, &k);
		k--; Modify(root, 1, n, l, r, k);
		printf("%d\n", root->sum);
	}
}