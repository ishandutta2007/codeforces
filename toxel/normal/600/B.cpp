#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

int a[N], ans[N];
pii b[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		b[i] = {x, i};
	}
	std::sort(b, b + m);
	for (int i = 0, j = 0; i < m; ++ i){
		while (j < n && a[j] <= b[i].first){
			++ j;
		}
		ans[b[i].second] = j;
	}
	for (int i = 0; i < m; ++ i){
		printf("%d%c", ans[i], " \n"[i == m - 1]);
	}
	return 0;
}