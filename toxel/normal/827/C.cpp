#include<bits/stdc++.h>

const int N = 10;
const int M = 100100;
const int MAX = 4;
inline int lowbit(int n){return n & (-n);}

int c[N][N][MAX][M], inv[M];
char s[M], str[M];
int test;

void add(int type1, int type2, int type3, int sit, int value){
	int sz = M / (type1 + 1);
	for ( ; sit < sz; sit += lowbit(sit)){
		c[type1][type2][type3][sit] += value;
	}
}

int query(int type1, int type2, int type3, int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret += c[type1][type2][type3][sit];
	}
	return ret;
}

int main(){
	scanf("%s%d", s + 1, &test);
	int len = strlen(s + 1);
	inv['A'] = 0;
	inv['T'] = 1;
	inv['G'] = 2;
	inv['C'] = 3;
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < N; ++ j){
			add(j, (i - 1) % (j + 1), inv[s[i]], (i + j) / (j + 1), 1);
		}
	}
	while (test --){
		int op;
		scanf("%d", &op);
		if (op == 1){
			int sit;
			scanf("%d%s", &sit, str);
			for (int i = 0; i < N; ++ i){
				add(i, (sit - 1) % (i + 1), inv[s[sit]], (sit + i) / (i + 1), -1);
				add(i, (sit - 1) % (i + 1), inv[str[0]], (sit + i) / (i + 1), 1);
			}
			s[sit] = str[0];
			continue;
		}
		int l, r;
		scanf("%d%d%s", &l, &r, str);
		int lene = strlen(str), ans = 0;
		for (int i = 0; i < lene; ++ i){
			int left = (i + l - 1) % lene;
			ans += query(lene - 1, left, inv[str[i]], (r + lene - 1) / lene - ((r - 1) % lene < left));
			if (l > 1){
				ans -= query(lene - 1, left, inv[str[i]], (l + lene - 2) / lene - ((l - 2) % lene < left));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}