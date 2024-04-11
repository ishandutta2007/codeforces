#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int MAXD = 28;
struct node {
	node* ch[2];
	int sum;
} TS[MAXN * MAXD], *root;
int q, TC;
void modify(int p, int delta) {
	node* now = root;
	for (int i = MAXD; i >= 0; --i) {
		int d = (p >> i) & 1;
		if (now->ch[d] == NULL) {
			now->ch[d] = TS + (++TC);
		}
		now = now->ch[d];
		now->sum += delta;
	}
}
int query(int p, int l) {
	int ret = 0;
	node* now = root;
	for (int i = MAXD; i >= 0; --i) {
		if (now == NULL) break;
		int ld = (l >> i) & 1, pd = (p >> i) & 1; 
		if (ld) {
			if (now->ch[pd] != NULL) {
				ret += now->ch[pd]->sum;
			}
		}
		now = now->ch[pd ^ ld];
	}
	return ret;
}
int main() {
	scanf("%d", &q);
	root = TS;
	for (int i = 1; i <= q; ++i) {
		int type, p, l;
		scanf("%d", &type);
		if (type == 1 || type == 2) {
			scanf("%d", &p);
			modify(p, type == 1 ? 1 : -1);
		}
		else {
			scanf("%d%d", &p, &l);
			printf("%d\n", query(p, l));
		}
	}
}