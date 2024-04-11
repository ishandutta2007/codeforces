#include<bits/stdc++.h>

const int N = 200010;

int vis[N], p[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &p[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i){
		if (vis[i]){
			continue;
		}
		++ cnt;
		while (!vis[p[i]]){
			i = p[i];
			vis[i] = true;
		}
	}
	if (cnt == 1){
		-- cnt;
	}
	int __cnt = 0;
	for (int i, x; i < n; ++ i){
		scanf("%d", &x);
		__cnt += x;
	}
	cnt += !(__cnt & 1);
	return printf("%d\n", cnt), 0;
}