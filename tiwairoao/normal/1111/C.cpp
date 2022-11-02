#include<cstdio>
#include<map>
using namespace std;
const int MAXN = 100000;
struct node{
	node *ch[2];
	int cnt; long long mn;
}pl[30*MAXN + 5], *tcnt=&pl[0], *root=&pl[0];
long long A, B;
void pushup(node *x, int l, int r) {
	if( x->cnt == 0 ) {
		x->mn = A;
		return ;
	}
	if( x->ch[0] == NULL ) {
		x->mn = min(B*x->cnt*(r-l+1), A + x->ch[1]->mn);
	}
	else if( x->ch[1] == NULL ) {
		x->mn = min(B*x->cnt*(r-l+1), x->ch[0]->mn + A);
	}
	else {
		x->mn = min(B*x->cnt*(r-l+1), x->ch[0]->mn + x->ch[1]->mn);
	}
}
void insert(node *x, int l, int r, int p) {
	if( l == r ) {
		x->cnt++;
		x->mn = B*x->cnt;
		return ;
	}
	int mid = (l + r) >> 1; x->cnt++;
	if( p <= mid ) {
		if( x->ch[0] == NULL )
			x->ch[0] = (++tcnt);
		insert(x->ch[0], l, mid, p);
	}
	else {
		if( x->ch[1] == NULL )
			x->ch[1] = (++tcnt);
		insert(x->ch[1], mid + 1, r, p);
	}
	pushup(x, l, r);
}
int main() {
	int n, k; scanf("%d%d%I64d%I64d", &n, &k, &A, &B);
	for(int i=1;i<=k;i++) {
		int x; scanf("%d", &x);
		insert(root, 1, (1<<n), x);
	}
	printf("%lld\n", root->mn);
}