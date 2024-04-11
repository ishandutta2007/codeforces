#include<bits/stdc++.h>

const int N = 2000010;

bool vis[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n << 1; ++ i){
		scanf("%d", &x);
		vis[x] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			ans += vis[i ^ j];
		}
	}
	return printf(ans & 1 ? "Koyomi\n" : "Karen\n"), 0;
}