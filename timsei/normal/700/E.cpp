#include <bits/stdc++.h>
using namespace std;

const int N = 211111;
const int M = N * 6;
const int Segment_Size = N * 50;

int n, m, x, y, last, ch[M][26], fa[M], MAX[M], sz;

char s[M];
int pos[M];

int copy(int x) {
	++ sz;
	for(int i = 0; i < 26; ++ i) ch[sz][i] = ch[x][i];
	fa[sz] = fa[x];
	return sz;
}

int add(int c) {
	int p, q, np, nq;
	p = last;
	np = last = ++ sz;
	MAX[np] = MAX[p] + 1;
	for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
	if(!p) {
		fa[np] = 1; return np;
	}
	else {
		q = ch[p][c];
		if(MAX[q] == MAX[p] + 1) {
			fa[np] = q; return np;
		}
		else {
			nq = copy(q); MAX[nq] = MAX[p] + 1;
			fa[q] = nq; fa[np] = nq;
			for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
		}
	}
	return np;
}

int rt[Segment_Size], tot, Ch[Segment_Size][2];

#define lc Ch[x][0]
#define rc Ch[x][1]

void add(int &x, int l, int r, int k) {
	if(!x) x = ++ tot;
	if(l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	if(k > mid) add(rc, mid + 1, r, k);
	else add(lc, l, mid, k);
}

int merge(int x, int y) {
	if(!x || !y) return x + y;
	int z = ++ tot;
	Ch[z][0] = merge(Ch[x][0], Ch[y][0]);
	Ch[z][1] = merge(Ch[x][1], Ch[y][1]);
	return z;
}

int query(int x, int l, int r, int L, int R) {
	if(!x) return 0;
	if(l == L && R == r) return 1;
	int mid = (l + r) >> 1;
	if(L > mid) return query(rc, mid + 1, r, L, R);
	else if(R <= mid) return query(lc, l, mid, L, R);
	else return query(lc, l, mid, L, mid) | query(rc, mid + 1, r, mid + 1, R);
}

queue <int> q;
vector <int> D;
vector <int> G[M];
int du[M], top[M], dp[M], who[M];

int main(void) {
	cin >> n;
	scanf("%s", s + 1);
	//srand(1245);
	//n = 2e5;
	//for(int i = 1; i <= n; ++ i) s[i] = rand() % 26 + 'a';
	last = ++ sz;
	for(int i = 1; i <= n; ++ i) {
		pos[i] = add(s[i] -= 'a');
		who[pos[i]] = i;
	}
	for(int i = 1; i <= sz; ++ i) {
		G[fa[i]].push_back(i);
		++ du[i];
	}
	q.push(1);
	while(!q.empty()) {
		int ind = q.front(); q.pop();
		D.push_back(ind);
		for(int i = 0; i < (int) G[ind].size(); ++ i) {
			if(-- du[G[ind][i]] == 0) {
				q.push(G[ind][i]);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		add(rt[pos[i]], 1, n, i);
	}
	reverse(D.begin(), D.end());
	for(int i = 0; i < (int) D.size(); ++ i) {
		rt[fa[D[i]]] = merge(rt[fa[D[i]]], rt[D[i]]);
		who[fa[D[i]]] = who[D[i]];
	}
	//cerr << "----------------------------" << endl;
	//cerr << tot << endl;
	//for(int i = 1; i <= sz; ++ i) cerr << i <<" " << MAX[i] <<" " << who[i] << " " << fa[i] << endl;
	reverse(D.begin(), D.end());
	int ans = 0;
	for(int i = 1; i < (int) D.size(); ++ i) {
		int x = D[i], F = fa[D[i]];
		if(F == 1) {
			dp[x] = 1; top[x] = x;
		}
		else if(query(rt[top[F]], 1, n, who[x] - (MAX[x] - MAX[top[F]]), who[x] - 1)) {
			dp[x] = dp[F] + 1; top[x] = x;
		}
		else top[x] = top[F], dp[x] = dp[F];
		ans = max(ans, dp[x]);
	}
	cout << ans <<  endl;
}