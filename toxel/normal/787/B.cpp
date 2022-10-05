#include<bits/stdc++.h>

const int N = 100010;

int cnt[2][N];
std::vector <int> rollback;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, k; i < m; ++ i){
		scanf("%d", &k);
		rollback.clear();
		for (int j = 0, x; j < k; ++ j){
			scanf("%d", &x);
			if (x > 0){
				++ cnt[0][x];
			}
			else{
				++ cnt[1][-x];
			}
			rollback.push_back(std::abs(x));
		}
		bool flag = true;
		for (auto u : rollback){
			if (cnt[0][u] && cnt[1][u]){
				flag = false;
			}
			cnt[0][u] = cnt[1][u] = 0;
		}
		if (flag){
			return printf("YES\n"), 0;
		}
	}
	return printf("NO\n"), 0;
}