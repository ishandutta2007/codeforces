#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
int arr[100100], nxt[100100], col[100100];

struct node {
	int val;
	node *l, *r;
	node() { val = 0; l = r = 0; }
	node(int v) { val = v; l = r = 0; }
	void init(int s, int e) {
		if (s == e) return;
		int m = (s + e) >> 1;
		l = new node();
		l->init(s, m);
		r = new node();
		r->init(m + 1, e);
	}
	int findkth(int s, int e, int k) {
		if (s == e) return s;
		int m = (s + e) >> 1;
		if (l->val <= k) return r->findkth(m + 1, e, k - l->val);
		else return l->findkth(s, m, k);
	}
} *head[200100];

node* upd(int s, int e, int idx, int val, node* with) {
	if (e < idx || idx < s) return with;
	if (s == e) {
		return new node(with->val + val);
	}
	node* tmp = new node();
	int m = (s + e) >> 1;
	tmp->l = upd(s, m, idx, val, with->l);
	tmp->r = upd(m + 1, e, idx, val, with->r);
	tmp->val = tmp->l->val + tmp->r->val;
	return tmp;
}

int nxtmem(int idx, int k) {
	return head[2 * idx]->findkth(0, n, k);
}

void init() {
	int i;
	head[2 * n] = new node();
	head[2 * n]->init(0, n);
	for (i = n - 1; i >= 0; i--) {
		if (nxt[i] == n) head[2 * i + 1] = head[2 * i + 2];
		else head[2 * i + 1] = upd(0, n, nxt[i], -1, head[2 * i + 2]);
		head[2 * i] = upd(0, n, i, 1, head[2 * i + 1]);
	}
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i <= n; i++) col[i] = n;
	for (i = n - 1; i >= 0; i--) {
		nxt[i] = col[arr[i]];
		col[arr[i]] = i;
	}
	init();
	for (i = 1; i <= n; i++) {
		int cnt = 0, p = 0;
		while (p < n) {
			int rp = p;
			p = nxtmem(p, i);
			cnt++;
		}
		printf("%d ", cnt);
	}
	printf("\n");

	return 0;
}