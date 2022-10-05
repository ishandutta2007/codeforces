#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> vec[N];
int n, m, k, max[N];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		for (int j = 0, x; j < m; ++ j){
			scanf("%d", &x);
			vec[j].push_back(x);
		}
	}
	max[n - 1] = n - 1;
	for (int j = 0; j < m; ++ j){
		int dp = n - 1;
		for (int i = n - 2; i >= 0; -- i){
			if (vec[j][i] > vec[j][i + 1]){
				dp = i;
			}
			max[i] = std::max(dp, max[i]);
		}
	}
	scanf("%d", &k);
	while (k --){
		int l, r;
		scanf("%d%d", &l, &r);
		printf(max[l - 1] >= r - 1 ? "Yes\n" : "No\n");
	}
	return 0;
}