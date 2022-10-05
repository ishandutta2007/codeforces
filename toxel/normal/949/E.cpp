#include<bits/stdc++.h>

const int N = 100010;

int a[N];
bool vis[2][N];
int ans;
int tmp[N], num[N];

void dfs(std::vector <int> vec, int now, int offset){
	if (vec.size() == 1 && std::abs(vec[0]) == 1 || vec.empty()){
		if (vec.size()){
			tmp[now ++] = vec[0] << offset;
		}
		if (now < ans){
			ans = now;
			memcpy(num, ::tmp, sizeof(int) * now);
		}
		return;
	}
	for (int i = -1; i <= 1; i += 2){
		std::vector <int> tmp;
		int cnt = 0;
		for (auto u : vec){
			if (u & 1){
				tmp.push_back(u - i >> 1);
				++ cnt;
			}
			else{
				tmp.push_back(u >> 1);
			}
		}
		int max = 0;
		for (auto u : tmp){
			max = std::max(max, std::abs(u));
		}
		for (int j = 0; j < 2; ++ j){
			for (int k = 0; k <= max; ++ k){
				vis[j][k] = false;
			}
		}
		for (auto u : tmp){
			vis[u > 0][std::abs(u)] = true;
		}
		tmp.clear();
		for (int j = 0; j < 2; ++ j){
			for (int k = 1; k <= max; ++ k){
				if (vis[j][k]){
					tmp.push_back(j ? k : -k);
				}
			}
		}
		if (cnt){
			::tmp[now ++] = i << offset;
		}
		dfs(tmp, now, offset + 1);
		if (cnt){
			-- now;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ vis[x > 0][std::abs(x)];
	}
	std::vector <int> vec;
	for (int i = 0; i < 2; ++ i){
		for (int j = 1; j < N; ++ j){
			if (vis[i][j]){
				vec.push_back(i ? j : -j);
			}
		}
	}
	ans = INT_MAX;
	dfs(vec, 0, 0);
	printf("%d\n", ans);
	for (int i = 0; i < ans; ++ i){
		printf("%d%c", num[i], " \n"[i == ans - 1]);
	}
	return 0;
}