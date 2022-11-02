#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000;
int n, m, c[N];

int top, head[N], next[N << 1], to[N << 1];

void addedge(int u, int v) {
	to[top] = v, next[top] = head[u], head[u] = top++;
}

int ans[N];
vector<pair<int, int> > que[N];
bool vis[N];

struct Node {
	int key, size, sum, w;
	Node *ch[2];

	void print() {
		cout << "key" << ' ' << key << ' ' << "size" << ' ' << size << ' ' << "sum" << ' ' << sum << ' ' << "w" << ' ' << w << endl;
	}
};

Node *null;

void update(Node *x) {
	x->sum = x->size + x->ch[0]->sum + x->ch[1]->sum;
}

void rotate(Node *&x, int t) {
	Node *y = x->ch[t];
	x->ch[t] = y->ch[t ^ 1];
	y->ch[t ^ 1] = x;
	update(x);
	update(y);
	x = y;
}

int randd() {
	return ((rand() & ((1 << 16) - 1)) << 10) ^ rand();
}

void insert(Node *&u, int val, int size) {
	if (u->key == -1) {
		u = new Node();
		u->key = val;
		u->sum = u->size = size;
		u->ch[0] = u->ch[1] = null;
		u->w = randd();
		return;
	}
	if (u->key == val) {
		u->size += size;
		u->sum += size;
		return;
	}
	int t = u->key < val;
	insert(u->ch[t], val, size);
	update(u);
	if (u->ch[t]->w < u->w) {
		rotate(u, t);
	}
}

int ask(Node *&u, int k) {
	if (u == null) {
		return 0;
	}
	if (u->key < k) {
		return ask(u->ch[1], k);
	} else {
		return ask(u->ch[0], k) + u->ch[1]->sum + u->size;
	}
}

void erase(Node *u) {
	if (u == null) {
		return;
	} else {
		erase(u->ch[0]);
		erase(u->ch[1]);
		delete u;
	}
}

void print(Node *u) {
	if (u == null) {
		return;
	}
	u->print();
	cout << "(" << endl;
	print(u->ch[0]);
	cout << "|" << endl;
	print(u->ch[1]);
	cout << ")" << endl;
}

struct Pair {
	map<int, int> col_cnt;
	Node *root;			
	
	Pair() {
		root = null;
	}

	void insert(int c, int s = 1) {
		int old_size = col_cnt[c];
		int new_size = old_size + s;
		if (old_size != 0) {
			::insert(root, old_size, -1);
		}
		if (new_size != 0) {
			::insert(root, new_size, 1);	
		}
		col_cnt[c] += s;
	}

	int ask(int k) {
		return ::ask(root, k);
	}

	int size() {
		return col_cnt.size();
	}
};

Pair *tr[N];

void merge(int u, int v) {
	if (tr[u]->size() < tr[v]->size()) {
		swap(tr[u], tr[v]);
	}
	erase(tr[v]->root);
	for (map<int, int>::iterator it = tr[v]->col_cnt.begin(); it != tr[v]->col_cnt.end(); ++it) {
		tr[u]->insert(it->first, it->second);
	}
	tr[v]->col_cnt.clear();	
}

void dfs(int u) {
	vis[u] = true;	
	tr[u] = new Pair();
	tr[u]->insert(c[u]);
	for (int j = head[u]; ~j; j = next[j]) {
		int v = to[j];
		if (!vis[v]) {
			dfs(v);
			merge(u, v);
		}
	}
	for (int i = 0; i < (int)que[u].size(); ++i) {
		int k = que[u][i].first, id = que[u][i].second;
		ans[id] = tr[u]->ask(k);
	}
}

int main() {
	null = new Node();
	null->key = -1;
	null->size = null->sum = 0;
	null->ch[0]= null->ch[1]= null;
	null->w = 1 << 30;
	top = 0;
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
	}
	for (int i = 0; i + 1 < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		addedge(u, v);	
		addedge(v, u);
	}
	for (int i = 0; i < m; ++i) {
		int u, k;
		scanf("%d%d", &u, &k);	
		--u;
		que[u].push_back(make_pair(k, i));
	}
	dfs(0);
	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}