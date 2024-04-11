#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define modn 1000000009ll
#define mod(x) ((x) % modn)
#define ll(x) static_cast<long long>(x)

inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }

void calc(int m[3][3], int v[3], int a[3]) {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			a[i] = mod(a[i] + ll(v[j]) * m[j][i]);
}

int tree[5500000];
int lazy[5500000][2];
int f[300003], fa[300003], mat[300003][3][3];
void unlaze(int ind, int from, int to) {
	if(!lazy[ind][0]) return;
	int v[3] = {lazy[ind][0], lazy[ind][1], lazy[ind][0] + lazy[ind][1]};
	int a[3] = {0, 0, 0};
	calc(mat[to - from], v, a);
	tree[ind] = mod(tree[ind] + a[2] - a[1] + modn);
	if(from != to) {
		lazy[l(ind)][0] = mod(lazy[l(ind)][0] + v[0]); lazy[l(ind)][1] = mod(lazy[l(ind)][1] + v[1]);
		a[0] = a[1] = a[2] = 0;
		int mid = (from + to) / 2;
		calc(mat[mid - from + 1], v, a);
		lazy[r(ind)][0] = mod(lazy[r(ind)][0] + a[0]); lazy[r(ind)][1] = mod(lazy[r(ind)][1] + a[1]);
	}
	lazy[ind][0] = lazy[ind][1] = 0;
}

void build_tree(int ind, int from, int to) {
	lazy[ind][0] = lazy[ind][1] = 0;
	if(from == to) {
		scanf("%d", &tree[ind]);
		return;
	}
	int mid = (from + to) / 2;
	build_tree(l(ind), from, mid);
	build_tree(r(ind), mid + 1, to);
	tree[ind] = mod(tree[l(ind)] + tree[r(ind)]);
}

int query_tree(int ind, int from, int to, int ql, int qr) {
	unlaze(ind, from, to);
	if(qr < from || ql > to) return 0;
	if(from >= ql && to <= qr) return tree[ind];
	int mid = (from + to) / 2;
	int a = query_tree(l(ind), from, mid, ql, qr);
	int b = query_tree(r(ind), mid + 1, to, ql, qr);
	return mod(a + b);
}

void update_tree(int ind, int from, int to, int ql, int qr) {
	unlaze(ind, from, to);
	if(qr < from || ql > to) return;
	int mid = (from + to) / 2;
	if(from >= ql && to <= qr) {
		tree[ind] = mod(tree[ind] + fa[to - ql + 1] - fa[from - ql] + modn);
		if(from != to) {
			int a[3] = {0, 0, 0};
			int v[3];
			v[0] = f[from - ql + 1]; v[1] = f[from - ql + 2]; v[2] = v[0] + v[1];
			lazy[l(ind)][0] = mod(lazy[l(ind)][0] + v[0]); lazy[l(ind)][1] = mod(lazy[l(ind)][1] + v[1]);
			calc(mat[mid - from + 1], v, a);
			lazy[r(ind)][0] = mod(lazy[r(ind)][0] + a[0]); lazy[r(ind)][1] = mod(lazy[r(ind)][1] + a[1]);
		}
		return;
	}
	update_tree(l(ind), from, mid, ql, qr);
	update_tree(r(ind), mid + 1, to, ql, qr);
	tree[ind] = mod(tree[l(ind)] + tree[r(ind)]);
}

void mult(int a[3][3], int b[3][3], int c[3][3]) {
	int i, j, k;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			for(k = 0; k < 3; k++)
				c[i][j] = mod(c[i][j] + ll(a[i][k]) * b[k][j]);
}

void pre_process() {
	int m[3][3] = {{0, 1, 1}, {1, 1, 1}, {0, 0, 1}};
	int i, j;
	f[0] = 0; fa[0] = 0;
	f[1] = 1; fa[1] = 1;
	f[2] = 1; fa[2] = 2;
	for(i = 3; i <= 300000; i++) {
		f[i] = mod(f[i - 1] + f[i - 2]);
		fa[i] = mod(fa[i - 1] + f[i]);
	}
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			mat[0][i][j] = (i == j);
	for(i = 1; i <= 300000; i++)
		mult(mat[i - 1], m, mat[i]);
}

int main() {
	int t, n, q, a, b, op, v;
	scanf("%d %d", &n, &q);
	pre_process();
	build_tree(1, 0, n - 1);
	while(q--) {
		scanf("%d %d %d", &op, &a, &b); a--; b--;
		if(op == 1)
			update_tree(1, 0, n - 1, a, b);
		else
			printf("%d\n", query_tree(1, 0, n - 1, a, b));
	}
	return 0;
}