#include<bits/stdc++.h>

const int N = 100010;

int n;
bool vis[N];

int main(){
	scanf("%d", &n);
	int ans = 0, now = 0;
	for (int i = 0, x; i < n << 1; ++ i){
		scanf("%d", &x);
		if (!vis[x]){
			vis[x] = true;
			++ now;
		}
		else{
			vis[x] = false;
			-- now;
		}
		ans = std::max(ans, now);
	}
	return printf("%d\n", ans), 0;
}