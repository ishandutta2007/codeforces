#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 11, L = 50005;
int n, tot, l[N], r[N], ll[N];
char s[L], t[N][L];

struct Node {
	int len, num;
	Node *ch[37], *fa;

	Node() {
		len = 0;
		fa = NULL;
		for (int i = 0; i < 37; ++i) {
			ch[i] = NULL;
		}
	}
} *last, *root, *pool[N * L];

void extend(int c) {
	Node *np = pool[++tot] = new Node;
	np->num = tot;
	np->len = last->len + 1;
	Node *p = last;
	while (p && !p->ch[c]) {
		p->ch[c] = np;
		p = p->fa;
	}
	if (!p) {
		np->fa = root;
	} else {
		Node *q = p->ch[c];
		if (q->len != p->len + 1) {
			Node *nq = pool[++tot] = new Node;
			nq->num = tot;
			nq->len = p->len + 1;
			for (int i = 0; i < 37; ++i) {
				nq->ch[i] = q->ch[i];
			}
			nq->fa = q->fa;
			q->fa = np->fa = nq;
			while (p && p->ch[c] == q) {
				p->ch[c] = nq;
				p = p->fa;
			}
		} else {
			np->fa = q;
		}
	}
	last = np;
}


long long ans;

int dp[N * L][N];
bool vis[N * L];

void DFS(int u) {
	if (vis[u]) {
		return;
	}
	vis[u] = true;
	for (int i = 0; i <= n; ++i) {
		if (pool[u]->ch[26 + i]) {
			dp[u][i] = 1;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (pool[u]->ch[i]) {
			int v = pool[u]->ch[i]->num;
			DFS(v);
			for (int j = 0; j <= n; ++j) {
				dp[u][j] += dp[v][j];
			}
		}
	}
	if (u && dp[u][0]) {
		bool flag = true;
		for (int i = 1; i <= n && flag; ++i) {
			flag = l[i] <= dp[u][i] && dp[u][i] <= r[i];
		}
		if (flag) {
			ans += pool[u]->len - pool[u]->fa->len;
		}
	}
}

int main() {
	last = root = pool[tot] = new Node;
	scanf("%s", s);
	int m = strlen(s);
	for (int i = 0; i < m; ++i) {
		extend(s[i] - 'a');
	}
	extend(26);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s%d%d", t[i], l + i, r + i);
		ll[i] = strlen(t[i]);
		for (int j = 0; j < ll[i]; ++j) {
			extend(t[i][j] - 'a');
		}
		extend(26 + i);
	}
	ans = 0;
	DFS(0);
	cout << ans << endl;
	return 0;
}