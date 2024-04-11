#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int B = 50;

struct Node {
	int id, k;
	friend bool operator < (Node a, Node b) {
		return a.k < b.k;
	}
}Q[N];

int n, w, ans[N], q, A[N], mn[20][N], mx[20][N], k;

int getnxt(int x) {
	int L = mn[0][x], R = mx[0][x];
	++ x;
	for(int i = 19; i >= 0; -- i) {
		if(x + (1 << i) > n + 1) continue;
		if(max(R, mx[i][x]) - min(L, mn[i][x]) <= k) {
			R = max(R, mx[i][x]);
			L = min(L, mn[i][x]);
			x += (1 << i);
		}
	}
//	cerr << x  <<' ' << L <<' ' << R << endl;
	return x;
}

namespace LCT {
	int val[N], ch[N][2], sz = 0, S[N], fa[N];
	void newnode(int x) {
		val[++ sz] = x; S[sz] = x;
	}

	bool isrt(int x) {
		return (ch[fa[x]][0] != x) && (ch[fa[x]][1] != x);
	}

	bool dir(int x) {
		return ch[fa[x]][1] == x;
	}

	void up(int x) {
		S[x] = S[ch[x][0]] + S[ch[x][1]] + val[x];
	}

	void rot(int x) {
		int F = fa[x], GF = fa[fa[x]], dx = dir(x), dF = dir(F);
		if(!isrt(F)) ch[GF][dF] = x; fa[x] = GF;
		fa[F] = x; fa[ch[x][!dx]] = F; 
		ch[F][dx] = ch[x][!dx]; ch[x][!dx] = F;
		up(F); up(x); up(GF);
	}

	void splay(int x) {
		for(; !isrt(x); rot(x)) {
			int y = fa[x], z = fa[y];
			if(!isrt(y)) ((dir(x) == dir(y)) ? rot(y) : rot(x));
		}
	}

	int access(int x) {
		int y = 0;
		for(; x; y = x, x = fa[x]) {
			splay(x); ch[x][1] = y; up(x);
			// don't forget up from all time
		}
		return y;
	}

	void link(int x, int y) {
//		access(x); 
		splay(x); fa[x] = y; assert(!ch[x][0]);
	}

	void cut(int x) {
		access(x); splay(x); fa[ch[x][0]] = 0; ch[x][0] = 0; up(x); // 
	}

}

using namespace LCT;

struct Opt {
	int x, y, k;
	friend bool operator < (Opt a, Opt b) {
		if(a.k == b.k) {
			if(a.y == -1) a.y = n + 2;
			if(b.y == -1) b.y = n + 2;
			return a.y < b.y;
		} else return a.k < b.k;
	}
}O[N * (B + 100)];

void dfs(int x) {
	if(ch[x][0]) dfs(ch[x][0]);
	printf("%d ", x);
	if(ch[x][1]) dfs(ch[x][1]);
}

int main() {
	scanf("%d%d%d", &n, &w, &q);
	
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
		mn[0][i] = A[i];
		mx[0][i] = A[i];
	}
	
	for(int i = 1; i < 20; ++ i) {
		for(int j = 1; j <= n - (1 << i) + 1; ++ j) {
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
		}
	}
	
	for(int i = 1; i <= q; ++ i) {
		scanf("%d", &Q[i].k);
		Q[i].k = w - Q[i].k;
		Q[i].id = i;
	}
	
	sort(Q + 1, Q + q + 1);
	
	int tot = 0;
	
	for(int i = 1; i <= n; ++ i) {
		int L = A[i], R = A[i];
		
		vector <int> All;
		
		for(int j = 1; j <= B + 1 && i + j - 1 <= n; ++ j) {
			L = min(L, A[i + j - 1]);
			R = max(R, A[i + j - 1]);
			O[++ tot] = (Opt){i, i + j, R - L};
			if(j == B + 1) O[tot].y = -1; 
		}
	}
	
	sort(O + 1, O + tot + 1);
	for(int i = 1; i <= n + 1; ++ i) newnode(1);
	
	int now = 1;
	for(int i = 1; i <= q; ++ i) {
		k = Q[i].k;
		while(O[now].k <= k && now <= tot) {
			cut(O[now].x);
			if(O[now].y >= 0)
			link(O[now].x, O[now].y);
			++ now;
		}
		
		int cur = 1, res = -2;
		while(cur <= n) {
			access(cur);
			splay(cur);
			res += S[cur];
			while(ch[cur][0]) cur = ch[cur][0];
			if(cur == n + 1) break;
			cur = getnxt(cur);
			if(cur == n + 1) ++ res;
		}
		ans[Q[i].id] = res;
	}
	for(int i = 1; i <= q; ++ i)
	printf("%d\n", ans[i]);
}