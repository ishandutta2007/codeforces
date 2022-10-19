#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;


int x, y;
vector <int> G[N];
int fa[N], S[N], n, m, v;

int getf(int x) {
	if(fa[x] == x) return x;
	int now = getf(fa[x]);
	S[x] ^= S[fa[x]];
	return fa[x] = now;
}

bool merge(int x, int y, int v) {
	int fx = getf(x); int  fy = getf(y);
	if(fx == fy) {
		if((S[x] ^ S[y]) != v) {
			return 0;
		} else return 1;
	}
	fa[fy] = fx;
	S[fy] = S[x] ^ S[y] ^ v;
	return 1;
}

int a[N], b[N], c[N], cnt = 0;

bool merge2(int x, int y, int v) {
	int fx = getf(x); int  fy = getf(y);
	if(fx == fy) {
		int now = (S[x] ^ S[y]), it = 0;
		while(now) {
			it += (now & 1);
			now >>= 1;
		}
		it = (it & 1);
		if(it != v) {
			return 0;
		} else return 1;
	}
	fa[fy] = fx;
	S[fy] = v ^ S[x] ^ S[y];
	return 1;
}


void fuck() {
	for(int i = 1; i <= n; ++ i) getf(i);
	for(int i = 1; i <= n; ++ i)
	cerr <<' ' << getf(i) <<' ' << S[i] << endl;
}

void rmain() {
	cnt = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) fa[i] = i, S[i] = 0;
	for(int i = 1; i <= n; ++ i) G[i].clear();
	bool ok = 1;
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d%d", &x, &y, &v);
		G[x].push_back(y);
		if(v != -1) {
			merge(x, y, v);
		}
	}
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d%d", &x, &y, &v);
		int now = merge2(x, y, v);
		ok &= now;
	}
	if(!ok) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i < n; ++ i) if(getf(i) != getf(i + 1)) merge(i, i + 1, 0);
		for(int i = 1; i <= n; ++ i) {
			for(int j = 0; j < (int) G[i].size(); ++ j) {
				printf("%d %d %d\n", i, G[i][j], S[i] ^ S[G[i][j]]);
			}
		}
	}
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}