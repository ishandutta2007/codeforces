#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct N {
	int x[12], y[12];
}t[400020];
int n, m, q;
char s[100020][12], o;
N mg(const N &a, const N &b) {
	N re;
	for (int i = 1; i <= m; i++) {
		if(b.x[i] == -1) {
			re.x[i] = a.x[b.y[i]];
			re.y[i] = a.y[b.y[i]];
		} else {
			re.x[i] = b.x[i];
			re.y[i] = b.y[i];
		}
	}
	return re;
}
void cg(int x, int l, int r, int p) {
	if (l == r) {
		for (int i = 1; i <= m; i++) {
			int p = i;
			int c = 0;
			while (p > 0 && p <= m && c < 3 && s[l][p] != '^') {
				if (s[l][p] == '>') {
					p++;
					c |= 1;
				} else if (s[l][p] == '<') {
					p--;
					c |= 2;
				}
			}
			if (c == 3) {
				t[x].x[i] = -2;
				t[x].y[i] = 0;
			} else if (p == 0 || p == m + 1) {
				t[x].x[i] = l;
				t[x].y[i] = p;
			} else {
				t[x].x[i] = -1;
				t[x].y[i] = p;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid) {
		cg(2 * x, l, mid, p);
	} else {
		cg(2 * x + 1, mid + 1, r, p);
	}
	t[x] = mg(t[2 * x], t[2 * x + 1]);
}
void bd(int x, int l, int r){
	if (l == r) {
		for (int i = 1; i <= m; i++) {
			int p = i;
			int c = 0;
			while (p > 0 && p <= m && c < 3 && s[l][p] != '^') {
				if (s[l][p] == '>') {
					p++;
					c |= 1;
				} else if (s[l][p] == '<') {
					p--;
					c |= 2;
				}
			}
			if (c == 3) {
				t[x].x[i] = -2;
				t[x].y[i] = 0;
			} else if (p == 0 || p == m + 1) {
				t[x].x[i] = l;
				t[x].y[i] = p;
			} else {
				t[x].x[i] = -1;
				t[x].y[i] = p;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	bd(2 * x, l, mid);
	bd(2 * x + 1, mid + 1, r);
	t[x] = mg(t[2 * x], t[2 * x + 1]);
}
N qy(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return t[x];
	}
	int mid = (l + r) >> 1;
	if (R <= mid) {
		return qy(2 * x, l, mid, L, R);
	} else if (L > mid) {
		return qy(2 * x + 1, mid + 1, r, L ,R);
	} else {
		N LL = qy(2 * x, l, mid, L, R);
		N RR = qy(2 * x + 1, mid + 1, r, L ,R);
		return mg(LL, RR);
	}
}
int main() {
	scanf("%d%d%d", &n, &m ,&q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	bd(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf(" %c %d %d", &o, &x, &y);
		if (o == 'C') {
			scanf(" %c", &o);
			s[x][y] = o;
			cg(1, 1, n, x);
		} else if (o == 'A') {
			N t = qy(1, 1, n, 1, x);
			if (t.x[y] == -1) {
				printf("%d %d\n", 0, t.y[y]);
			} else if (t.x[y] == -2) {
				printf("%d %d\n", -1, -1);
			} else {
				printf("%d %d\n", t.x[y], t.y[y]);
			}
		}
	}

}