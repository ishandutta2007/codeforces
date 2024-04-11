#include<bits/stdc++.h>

const int N = 1010;

int n, min[N];
std::vector <int> query;

int main(){
	memset(min, 0x7f, sizeof(min));
	scanf("%d", &n);
	/*if (n == 2){
		printf("1\n1\n");
		fflush(stdout);
		int x, y;
		scanf("%d%d", &x, &y);
		min[2] = y;
		printf("1\n2\n");
		fflush(stdout);
		scanf("%d%d", &x, &y);
		min[1] = x;
		return printf("-1\n%d %d\n", min[1], min[2]), 0;
	}*/
	int len = 0;
	for (int x = n; x; x >>= 1, ++ len);
	for (int i = 1; i <= len; ++ i){
		query.clear();
		for (int j = 1; j <= n; ++ j){
			int cnt = 0;
			for (int k = 0; k < len; ++ k){
				if (j >> k & 1){
					++ cnt;
				}
			}
			if (cnt == i){
				query.push_back(j);
			}
		}
		if (!query.size()){
			continue;
		}
		printf("%d\n", query.size());
		for (auto u : query){
			printf("%d ", u);
		}
		printf("\n");
		fflush(stdout);
		for (int j = 1, k = 0, x; j <= n; ++ j, ++ k){
			while (j <= n && (k >= query.size() || j != query[k])){
				scanf("%d", &x);
				min[j] = std::min(min[j], x);
				++ j;
			}
			if (j > n){
				break;
			}
			scanf("%d", &x);
		}
	}
	for (int i = 0; i < len; ++ i){
		query.clear();
		for (int j = 1; j <= n; ++ j){
			if (j >> i & 1){
				query.push_back(j);
			}
		}
		if (!query.size()){
			continue;
		}
		printf("%d\n", query.size());
		for (auto u : query){
			printf("%d ", u);
		}
		printf("\n");
		fflush(stdout);
		for (int j = 1, k = 0, x; j <= n; ++ j, ++ k){
			while (j <= n && (k >= query.size() || j != query[k])){
				scanf("%d", &x);
				min[j] = std::min(min[j], x);
				++ j;
			}
			if (j > n){
				break;
			}
			scanf("%d", &x);
		}
	}
	printf("-1\n");
	for (int i = 1; i <= n; ++ i){
		printf("%d ", min[i]);
	}
	return printf("\n"), 0;
}