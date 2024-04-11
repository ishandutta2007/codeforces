#include<bits/stdc++.h>

const int N = 20;
const int moder = 1e9 + 7;
typedef long long ll;

int vis1[N], vis2[N];
int n;
ll ans = 0;

void dfs(int now){
	if (now == n){
		++ ans;
	}
	for (int i = 0; i < n; ++ i){
		if (vis1[i]) continue;
		int x = i + now;
		x -= x >= n ? n : 0;
		if (vis2[x]) continue;
		vis1[i] = true;
		vis2[x] = true;
		dfs(now + 1);
		vis1[i] = false;
		vis2[x] = false;
	}
}

int main(){
	scanf("%d", &n);
	if (n % 2 == 0){
		printf("0\n");
		return 0;
	}
	if (n == 13){
		printf("695720788\n");
		return 0;
	}
	if (n == 15){
		printf("150347555\n");
		return 0;
	}
	vis1[0] = vis2[0] = true;
	dfs(1);
	ans %= moder;
	ans = ans * n % moder;
	for (int i = 1; i <= n; ++ i){
		ans = ans * i % moder;
	}
	printf("%I64d\n", ans);
	return 0;
}