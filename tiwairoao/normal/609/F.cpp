#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2 * int(1E5);
long long p[MAXN + 5], b[MAXN + 5], Point[2*MAXN + 5];
int pcnt = 0;
struct node{
	int le, ri;
	int col, num;long long msqt;
}tree[8*MAXN + 5];
struct Node{
	long long x, t;
	int id, Eat;
}Frog[MAXN + 5];
bool cmp1(Node a, Node b) {
	return a.x < b.x;
}
bool cmp2(Node a, Node b) {
	return a.id < b.id;
}
void PushDown(int x) {
	if( tree[x].col != -1 && tree[x].col != 0 ) {
		tree[x*2].col = tree[x*2+1].col = tree[x].col;
		tree[x*2].msqt = tree[x*2+1].msqt = 0;
		tree[x*2].num = tree[x*2+1].num = 0;
	}
}
void PushUp(int x) {
	if( tree[x*2].col != -1 && tree[x*2].col == tree[x*2+1].col )
		tree[x].col = tree[x*2].col;
	tree[x].msqt = tree[x*2].msqt + tree[x*2+1].msqt;
	tree[x].num = tree[x*2].num + tree[x*2+1].num;
}
void Build(int x, int l, int r) {
	tree[x].le = l, tree[x].ri = r;
	tree[x].col = tree[x].msqt = tree[x].num = 0;
	if( l == r ) return ;
	int Mid = (l+r) / 2;
	Build(x*2, l, Mid);
	Build(x*2+1, Mid+1, r);
}
long long Insert_1(int x, int l, int r, int c) {
	if( tree[x].le > r || tree[x].ri < l )
		return -1;
	if( l <= tree[x].le && tree[x].ri <= r ) {
		long long ret = tree[x].msqt;
		tree[x].col = c; tree[x].msqt = 0;
		Frog[c].Eat += tree[x].num; tree[x].num = 0;
		return ret;
	}
	PushDown(x);
	tree[x].col = -1;
	long long p = Insert_1(2*x, l, r, c);
	long long q = Insert_1(2*x+1, l, r, c);
	PushUp(x);
	long long ret = 0;
	if( p != -1 ) ret += p;
	if( q != -1 ) ret += q;
	return ret;
}
int Insert_2(int x, int pos, long long siz) {
	if( tree[x].le > pos || tree[x].ri < pos )
		return -1;
	if( pos <= tree[x].le && tree[x].ri <= pos && tree[x].col == 0 ) {
		tree[x].msqt += siz;
		tree[x].num++;
		return 0;
	}
	if( tree[x].col != -1 && tree[x].col != 0 ) {
		Frog[tree[x].col].Eat++;
		return tree[x].col;
	}
	PushDown(x);
	int p = Insert_2(2*x, pos, siz);
	int q = Insert_2(2*x+1, pos, siz);
	PushUp(x);
	if( p == -1 ) return q;
	else return p;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%I64d%I64d", &Frog[i].x, &Frog[i].t);
		Point[++pcnt] = Frog[i].x;
		Frog[i].id = i;
	}
	sort(Frog+1, Frog+n+1, cmp1);
	for(int i=1;i<=m;i++) {
		scanf("%I64d%I64d", &p[i], &b[i]);
		Point[++pcnt] = p[i];
	}
	sort(Point+1, Point+pcnt+1);
	pcnt = unique(Point+1, Point+pcnt+1) - Point - 1;
	Build(1, 1, pcnt);
	for(int i=n;i>=1;i--) {
		int le = lower_bound(Point+1, Point+pcnt+1, Frog[i].x) - Point;
		int ri = upper_bound(Point+1, Point+pcnt+1, Frog[i].x+Frog[i].t) - Point - 1;
		Insert_1(1, le, ri, i);
	}
	for(int i=1;i<=m;i++) {
		int pos = lower_bound(Point+1, Point+pcnt+1, p[i]) - Point;
		int q = Insert_2(1, pos, b[i]);
		long long k = b[i];
		if( q ) {
			while( k ) {
				int le = upper_bound(Point+1, Point+pcnt+1, Frog[q].x+Frog[q].t) - Point;
				Frog[q].t += k;
				int ri = upper_bound(Point+1, Point+pcnt+1, Frog[q].x+Frog[q].t) - Point - 1;
				if( le <= ri ) k = Insert_1(1, le, ri, q);
				else break;
			}
		}
	}
	sort(Frog+1, Frog+n+1, cmp2);
	for(int i=1;i<=n;i++)
		printf("%d %I64d\n", Frog[i].Eat, Frog[i].t);
}