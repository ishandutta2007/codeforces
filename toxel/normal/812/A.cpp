#include<bits/stdc++.h>

const int N = 4;

int vis[N], _vis[N];

int main(){
	for (int i = 0, a, b, c, d; i < 4; ++ i){
		scanf("%d%d%d%d", &a, &b, &c, &vis[i]);
		if (a){
			_vis[i] = _vis[(i + 3) % N] = 1;
		}
		if (b){
			_vis[i] = _vis[(i + 2) % N] = 1;
		}
		if (c){
			_vis[i] = _vis[(i + 1) % N] = 1;
		}
	}
	for (int i = 0; i < N; ++ i){
		if (vis[i] && _vis[i]){
			return printf("YES\n"), 0;
		}
	}
	return printf("NO\n"), 0;
}