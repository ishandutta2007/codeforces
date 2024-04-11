#include<bits/stdc++.h>

const int N = 110;
const int M = 1100000;

std::vector <int> Hash[M], mach[M];
bool used[N];
int n, q;

int main(){
	scanf("%d%d", &n, &q);
	int now_time = 0;
	for (int i = 1, t, k, d; i <= q; ++ i){
		scanf("%d%d%d", &t, &k, &d);
		while (now_time <= t){
			for (int j = 0; j < Hash[now_time].size(); ++ j){
				int x = Hash[now_time][j];
				for (int k = 0; k < mach[x].size(); ++ k){
					used[mach[x][k]] = false;
				}
			}
			++ now_time;
		}
		int ans = 0;
		for (int j = 1; j <= n && mach[i].size() < k; ++ j){
			if (used[j]){
				continue;
			}
			ans += j;
			mach[i].push_back(j);
		}
		if (mach[i].size() < k){
			printf("-1\n");
		}
		else{
			printf("%d\n", ans);
			for (int j = 0; j < mach[i].size(); ++ j){
				used[mach[i][j]] = true;
			}
			Hash[t + d].push_back(i);
		}
	}
	return 0;
}