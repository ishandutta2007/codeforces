#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 501000;
int n, m, p, now, tot, no[maxn], v[maxn];
char s[maxn], Q[maxn];
bool visit[maxn][2];
struct node {
	int type, no;
	node *l, *r;
} TS[maxn], *cur;
void del(node* now) {
	if (now->l != NULL) now->l->r = now->r;
	if (now->r != NULL) now->r->l = now->l;
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) 
		if (s[i] == '(') {
			no[i] = ++tot;
			v[++now] = tot;
		}
		else no[i] = v[now--];
	
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') TS[i].type = 0;
		else TS[i].type = 1;
		TS[i].no = no[i];
		if (i == 1) TS[i].l = NULL;
		else TS[i].l = TS + i - 1;
		if (i == n) TS[i].r = NULL;
		else TS[i].r = TS + i + 1;
	}
	
	cur = TS + p;
	scanf("%s", Q + 1);
	for (int i = 1; i <= m; ++i) {
		if (Q[i] == 'L') cur = cur->l;
		if (Q[i] == 'R') cur = cur->r;
		if (Q[i] == 'D') {
			if (cur->type == 0) {
				node* ll = cur->l, *now = cur;
				int no = cur->no;
				while (!(now->type == 1 && now->no == no)) {
					node* tmp = now->r;
					del(now);
					now = tmp; 
				}
				if (now->r == NULL) cur = ll;
				else cur = now->r;
				del(now);
			}
			else {
				node* rr = cur->r, *now = cur;
				int no = cur->no;
				while (!(now->type == 0 && now->no == no)) {
					node* tmp = now->l;
					del(now);
					now = tmp;
				}
				if (rr == NULL) cur = now->l;
				else cur = rr;
				del(now);
			}
		}
	}
	visit[cur->no][cur->type] = true;
	node* now = cur->l;
	while (now != NULL) {
		visit[now->no][now->type] = true;
		now = now->l;
	}
	now = cur->r;
	while (now != NULL) {
		visit[now->no][now->type] = true;
		now = now->r;
	}
	for (int i = 1; i <= n; ++i) {
		int type = s[i] == '(' ? 0 : 1;
		if (visit[no[i]][type]) printf("%c", s[i]);
	}
	printf("\n");
}