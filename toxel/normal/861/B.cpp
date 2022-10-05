#include<bits/stdc++.h>

const int N = 110;

int sit[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, k, f; i < m; ++ i){
		scanf("%d%d", &k, &f);
		sit[k] = f;
	}
	int ans = -1;
	for (int i = 1; i < N; ++ i){
		bool flag = true;
		for (int j = 1; j < N; ++ j){
			if (sit[j] && (j - 1) / i + 1 != sit[j]){
				flag = false;
				continue;
			}
		}
		if (flag){
			int x = (n - 1) / i + 1;
			if (!~ans){
				ans = x;
			}
			else if (ans != x) return printf("-1\n"), 0;
		}
	}
	return printf("%d\n", ans), 0;
}