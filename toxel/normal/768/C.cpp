#include<bits/stdc++.h>

const int N = 100010;
const int M = 1 << 10;

int n, k, x, a[N], cnt[2][M];

int main(){
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		++ cnt[0][a[i]];
	}
	int pre = 0, now = 1;
	for (int i = 0; i < k; ++ i){
		int now_cnt = 0;
		memset(cnt[now], 0, sizeof(cnt[now]));
		for (int j = 0; j < M; ++ j){
			if (now_cnt & 1){
				cnt[now][j ^ x] += cnt[pre][j] >> 1;
				cnt[now][j] += cnt[pre][j] - (cnt[pre][j] >> 1);
			}
			else{
				cnt[now][j] += cnt[pre][j] >> 1;
				cnt[now][j ^ x] += cnt[pre][j] - (cnt[pre][j] >> 1);
			}
			now_cnt += cnt[pre][j];
		}
		pre ^= 1;
		now ^= 1;
	}
	int min = INT_MAX, max = 0;
	for (int i = 0; i < M; ++ i){
		if (cnt[pre][i]){
			min = std::min(min, i);
			max = std::max(max, i);
		}
	}
	return printf("%d %d\n", max, min), 0;
}