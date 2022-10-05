#include<bits/stdc++.h>

const int MAX = 1 << 9;

int n, m, k, q;
int seg[MAX << 1][MAX << 1];

void add(int sit1, int sit2, int value){
	for (sit1 += MAX; sit1; sit1 >>= 1){
		int sit = sit2 + MAX;
		seg[sit1][sit] = sit1 >= MAX ? value : std::max(seg[sit1 << 1][sit], seg[sit1 << 1 | 1][sit]);
		for (sit >>= 1; sit; sit >>= 1){
			seg[sit1][sit] = std::max(seg[sit1][sit << 1], seg[sit1][sit << 1 | 1]);
		}
	}
}

int query(int l1, int r1, int l2, int r2){
	int ret = 0;
	for (l1 += MAX, r1 += MAX + 1; l1 < r1; l1 >>= 1, r1 >>= 1){
		if (l1 & 1){
			for (int l = l2 + MAX, r = r2 + MAX + 1; l < r; l >>= 1, r >>= 1){
				if (l & 1){
					ret = std::max(ret, seg[l1][l ++]);
				}
				if (r & 1){
					ret = std::max(ret, seg[l1][-- r]);
				}
			}
			++ l1;
		}
		if (r1 & 1){
			-- r1;
			for (int l = l2 + MAX, r = r2 + MAX + 1; l < r; l >>= 1, r >>= 1){
				if (l & 1){
					ret = std::max(ret, seg[r1][l ++]);
				}
				if (r & 1){
					ret = std::max(ret, seg[r1][-- r]);
				}
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			add(i, j, INT_MAX);
		}
	}
	for (int i = 0, x, y, t; i < q; ++ i){
		scanf("%d%d%d", &x, &y, &t);
		-- x, -- y;
		add(x, y, t);
	}
	int ans = INT_MAX;
	for (int i = 0; i <= n - k; ++ i){
		for (int j = 0; j <= m - k; ++ j){
			ans = std::min(ans, query(i, i + k - 1, j, j + k - 1));
		}
	}
	return printf("%d\n", ans == INT_MAX ? -1 : ans), 0;
}