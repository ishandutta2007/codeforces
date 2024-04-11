#include<bits/stdc++.h>

const int N = 110;

int a[N], b[N], cnt[N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m - 1; ++ i){
		int x = (a[i + 1] - a[i] + n - 1) % n + 1;
		if (b[a[i]] && b[a[i]] != x){
			return printf("-1\n"), 0;
		}
		b[a[i]] = x;
	}
	for (int i = 1; i <= n; ++ i){
		++ cnt[b[i]];
	}
	for (int i = 1; i <= n; ++ i){
		if (cnt[i] > 1){
			return printf("-1\n"), 0;
		}
	}
	for (int i = 1, j = 1; i <= n; ++ i){
		while (j <= n && cnt[j]){
			++ j;
		}
		if (!b[i]){
			b[i] = j ++;
		}
	}
	for (int i = 1; i <= n; ++ i){
		printf("%d%c", b[i], " \n"[i == n]);
	}
	return 0;
}