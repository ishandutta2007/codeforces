#include<bits/stdc++.h>

const int N = 5010;
typedef std::pair <int, int> pii;

int cnt[N], a[N], ans[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i){
		pii max = {0, 0};
		memset(cnt, 0, sizeof(cnt));
		for (int j = i; j <= n; ++ j){
			++ cnt[a[j]];
			max = std::max(max, {cnt[a[j]], -a[j]});
			++ ans[-max.second];
		}
	}
	for (int i = 1; i <= n; ++ i){
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;	
}