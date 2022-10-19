#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct NODE {
	int val, pos;
	friend bool operator < (NODE a, NODE b) {
		return a.val < b.val;
	}
}T[N];

int A[N], n, m, x, y, fa[N], s;
bool vis[N];

vector < vector <int> > ans, cir;

void print(void) {
	printf("%d\n", ans.size());
	for(int i = 0; i < (int) ans.size(); ++ i) {
		cout << ans[i].size() << endl;
		for(int j = 0; j < (int) ans[i].size(); ++ j) printf("%d ", ans[i][j]);
		puts("");
	}
}

int pos[N];

void get(int x) {
	vector <int> cur;
	cur.clear();
	cur.push_back(x);
	while(1) {
		vis[x] = 1;
		x = pos[x];
		if(vis[x]) break;
		cur.push_back(x);
	}
	cir.push_back(cur);
}

int getf(int x) {
	return (fa[x] == x) ? x : (fa[x] = getf(fa[x]));
}

bool used[N];

vector <int> Self;
int where[N];
int k = 0;

void solve(int l, int r) {
	vector <int> who;
	who.clear();
	vector <int> cxt;
	cxt.clear();
	int it = T[l].val;
	for(int i = l; i <= r; ++ i) {
		if(T[T[i].pos].val == T[i].val) {
			who.push_back(T[i].pos);
		}
		else cxt.push_back(T[i].pos);
	}
	for(int i = 0; i < (int) who.size(); ++ i) T[who[i]].pos = who[i], used[who[i]] = 1;
	for(int i = l; i <= r; ++ i) {
		if(!used[i]) {
			T[i].pos = cxt.back();
			cxt.pop_back();
		}
	}
}

main(void) {
	scanf("%d%d" ,&n, &s);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) T[i].pos = i, T[i].val = A[i];
	sort(T + 1, T + n + 1);
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	int self = 0;
	for(int i = 1; i <= n; ++ i) {
		if(T[i].val == T[T[i].pos].val) ++ self;
	}
	
	int L = 1, R = 0;
	
	for(int i = 2; i <= n; ++ i) {
		if(T[i].val != T[i - 1].val) {
			R = i - 1;
			solve(L, R);
			L = i;
			continue;
		}
	}
	solve(L, n);
	memset(used, 0, sizeof(used));
	for(int i = 1; i <= n; ++ i) fa[getf(T[i].pos)] = getf(i);
	int last = 1;
	if(T[last].pos == last) last = 0;
	for(int i = 2; i <= n; ++ i) {
		if(T[i].pos == i) continue;
		if(!last) {
			last = i;
			continue;
		}
		if(T[i].val == T[last].val) {
			if(getf(i) != getf(last)) {
				swap(T[i], T[last]);
				fa[getf(i)] = getf(last);
			}
		}
		last = i;
	}
	if(s < n - self) {
		puts("-1");
		return 0;
	}
	for(int i = 1; i <= n; ++ i) pos[T[i].pos] = i;
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i] && (T[i].pos != i)) get(i);
	}
	int now = s - (n - self);
	now = min(now, (int)cir.size());
	if(now <= 2) {
		ans = cir;
	}
	else {
		vector <int> cur;
		cur.clear();
		for(int i = 0; i < now; ++ i) {
			for(int j = 0; j < (int) cir[i].size(); ++ j) cur.push_back(cir[i][j]);
		}
		ans.push_back(cur);
		cur.clear();
		for(int i = 0; i < now; ++ i) cur.push_back(cir[i][0]);
		reverse(cur.begin(), cur.end());
		ans.push_back(cur);
		for(int i = now; i < (int)cir.size(); ++ i) ans.push_back(cir[i]);
	}
	print();
}