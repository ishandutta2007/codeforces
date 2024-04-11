#include <bits/stdc++.h>
using namespace std;

const int MaxN = 300005;

int n, m, Ans;
int fa[MaxN], size[MaxN][2], col[MaxN], ass[MaxN];
char s[MaxN];

vector <int> son[MaxN];

int find(int x) {
	if (x == fa[x]) return x;
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	col[x] ^= col[tmp];
	return fa[x];
}

void chg(int x, int t) {
	int fx = find(x);
	if (ass[fx] != -1) {
		Ans += t * size[fx][ass[fx]];
	} else {
		Ans += t * min(size[fx][0], size[fx][1]);
	}
}

int main() {
	
//	freopen("1.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= m; ++ i) {
		int K; scanf("%d", &K);
		for (int j = 1; j <= K; ++ j) {
			int x; scanf("%d", &x);
			son[x].push_back(i); 
		}
	}
	for (int i = 1; i <= m; ++ i) {
		fa[i] = i;
		col[i] = 0;
		size[i][0] = 1;
		size[i][1] = 0;
		ass[i] = -1;
	}
	Ans = 0;
	for (int i = 1; i <= n; ++ i) {
		
//		printf("work %d\n", i);
		
		if (son[i].empty()) {
			// pass
		} else if (son[i].size() == 1) {
			int x = son[i][0];
			int fx = find(x);
			chg(fx, -1);
			ass[fx] = col[x] ^ (s[i] - '0');
			chg(fx, 1);
		} else {
			int x = son[i][0], y = son[i][1];
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				chg(fx, -1);
				chg(fy, -1);
				
				if (size[fx][0] + size[fx][1] > size[fy][0] + size[fy][1]) {
					swap(fx, fy);
				}
				int edg_val = (s[i] - '0') ^ 1;
				fa[fx] = fy;
				col[fx] = col[y] ^ col[x] ^ edg_val;
				for (int j = 0; j < 2; ++ j) {
					size[fy][j ^ col[fx]] += size[fx][j];
				}
				if (ass[fx] != -1) {
					ass[fy] = ass[fx] ^ col[fx];
				}
				
				chg(fy, 1);
			}
		}
		printf("%d\n", Ans);
	}
	return 0;
}