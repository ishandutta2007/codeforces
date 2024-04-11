#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> vec[N];
int n, f[N], g[N], h[N];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &f[i]);
		vec[f[i]].push_back(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i){
		if (!vec[i].size()){
			continue;
		}
		++ cnt;
		bool flag = false;
		for (auto u : vec[i]){
			if (u == i){
				flag = true;
				break;
			}
		}
		if (!flag){
			return printf("-1\n"), 0;
		}
		h[cnt] = i;
		for (auto u : vec[i]){
			g[u] = cnt;
		}
	}
	printf("%d\n", cnt), 0;
	for (int i = 1; i <= n; ++ i){
		printf("%d ", g[i]);
	}
	putchar('\n');
	for (int i = 1; i <= cnt; ++ i){
		printf("%d ", h[i]);
	}
	putchar('\n');
	return 0;
}