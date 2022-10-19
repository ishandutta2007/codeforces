#include <bits/stdc++.h>
using namespace std;

const int N = 17 * (1 << 17) + 5;

int n, m, x, y, A[N], ch[N][2], sz, S[N], l, r, rt, ans;

void add(int x) {
	int cur = rt; ++ S[cur];
	for(int i = 16; i >= 0; -- i) {
		if(!ch[cur][(x >> i) & 1]) {
			ch[cur][(x >> i) & 1] = ++ sz;
		}
		cur = ch[cur][(x >> i) & 1];
		++ S[cur];
	}
}

int get(int l, int r, int L, int R) {
	if(r < L) return 0;
	if(l > R) return 0;
	return min(R, r) - max(L, l) + 1;
}

struct Node {
	int i, cur;
};

bool ok = 0;

void dfs(int x, vector <Node> d) {
	for(int i = 0; i < (int) d.size(); ++ i) {
//		cerr << S[d[i].cur] << ' ' << get(l, r, d[i].i * (1 << (16 - x)), (d[i].i + 1) * (1 << (16 - x)) - 1) << endl;
		if(S[d[i].cur] != get(l, r, d[i].i * (1 << (17 - x)), (d[i].i + 1) * (1 << (17 - x)) - 1)) {
			return;
		}
	}
	if(x == 17) {
		ok = 1;
		return;
	}
	vector <Node> tmp;
	for(int i = 0; i < (int) d.size(); ++ i) {
		if(S[d[i].cur]) {
			tmp.push_back(d[i]);
		}
	}
	swap(d, tmp);
	tmp.clear();
	for(int i = 0; i < (int) d.size(); ++ i) {
		tmp.push_back((Node){d[i].i * 2, ch[d[i].cur][0]});
		tmp.push_back((Node){d[i].i * 2 + 1, ch[d[i].cur][1]});
	}
	dfs(x + 1, tmp);
	if(ok) return;
	ans += (1 << (16 - x));
	tmp.clear();
	for(int i = 0; i < (int) d.size(); ++ i) {
		tmp.push_back((Node){d[i].i * 2 + 1, ch[d[i].cur][0]});
		tmp.push_back((Node){d[i].i * 2, ch[d[i].cur][1]});
	}
	dfs(x + 1, tmp);
	if(ok) return;
	ans -= (1 << (16 - x));
}

void rmain() {
	for(int i = 1; i <= sz; ++ i) ch[i][0] = ch[i][1] = S[i] = 0;
	sz = 0; rt = ++ sz;
	scanf("%d%d", &l, &r);
	for(int i = 1; i <= r - l + 1; ++ i) {
		scanf("%d", &x);
		add(x);
	}
	ok = 0;
	ans = 0;
	vector <Node> d; d.push_back((Node){0, 1});
	dfs(0, d);
	printf("%d\n", ans);
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}