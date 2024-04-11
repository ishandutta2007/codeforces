#include<bits/stdc++.h>

const int MAX = 1 << 18;
const int N = 200010;
const int M = 5;

struct matrix{
	int a[M][M];
	
	matrix(){
		memset(a, 0x7f, sizeof(a));
	}
};

matrix seg[MAX << 1];
int n, q;
char s[N];

matrix merge(const matrix &a, const matrix &b){
	matrix ret;
	for (int k = 0; k < M; ++ k){
		for (int i = 0; i < M; ++ i){
			for (int j = 0; j < M; ++ j){
				if (i > k || k > j){
					continue;
				}
				if (a.a[i][k] > 1e9 || b.a[k][j] > 1e9){
					continue;
				}
				ret.a[i][j] = std::min(ret.a[i][j], a.a[i][k] + b.a[k][j]);
			}
		}
	}
	return ret;
}

void build(){
	for (int i = MAX; i < MAX + n; ++ i){
		for (int j = 0; j < M; ++ j){
			seg[i].a[j][j] = 0;
		}
		switch (s[i - MAX]){
			case '3': case '4': case '5': case '8': case '9': break;
			case '2': seg[i].a[0][1] = 0; seg[i].a[0][0] = 1; break;
			case '0': seg[i].a[1][2] = 0; seg[i].a[1][1] = 1; break;
			case '1': seg[i].a[2][3] = 0; seg[i].a[2][2] = 1; break;
			case '7': seg[i].a[3][4] = 0; seg[i].a[3][3] = 1; break;
			case '6': seg[i].a[3][3] = seg[i].a[4][4] = 1; break;
			default: break;
		}
	}
	for (int i = MAX - 1; i; -- i){
		seg[i] = merge(seg[i << 1], seg[(i << 1) + 1]);
	}
}

int query(int left, int right){
	matrix ret_left, ret_right;
	for (int i = 0; i < M; ++ i){
		ret_left.a[i][i] = ret_right.a[i][i] = 0;
	}
	for (int l = left + MAX - 1, r = right + MAX; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			ret_left = merge(ret_left, seg[l ++]);
		}
		if (r & 1){
			ret_right = merge(seg[-- r], ret_right);
		}
	}
	return merge(ret_left, ret_right).a[0][4];
}

int main(){
	scanf("%d%d%s", &n, &q, s);
	build();
	for (int i = 0, l, r; i < q; ++ i){
		scanf("%d%d", &l, &r);
		int x = query(l, r);
		printf("%d\n", x > 1e9 ? -1 : x);
	}
	return 0;
}