#include<bits/stdc++.h>

const int N = 110;

std::pair <int, int> p[N];
int n, w;
int ans[N], tea[N];

int main(){
	scanf("%d%d", &n, &w);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		p[i] = {x, i};
	}
	std::sort(p, p + n, std::greater <std::pair <int, int>>());
	for (int i = 0; i < n; ++ i){
		tea[i] = p[i].first + 1 >> 1;
		w -= tea[i];
	}
	if (w < 0){
		return printf("-1\n"), 0;
	}
	for (int i = 0; w; i = (i + 1) % n){
		if (tea[i] < p[i].first){
			++ tea[i];
			-- w;
		}
	}
	for (int i = 0; i < n; ++ i){
		ans[p[i].second] = tea[i];
	}
	for (int i = 0; i < n; ++ i){
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}