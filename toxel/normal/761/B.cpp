#include<bits/stdc++.h>

const int N = 110;

int a[N], b[N], n, L;

int main(){
	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; ++ i){
		int dif = (a[0] - b[i] + L) % L;
		bool flag = true;
		for (int j = 0; j < n; ++ j){
			int x = (a[j] - b[(i + j) % n] + L) % L;
			if (x != dif){
				flag = false;
				break;
			}
		}
		if (flag){
			return printf("YES\n"), 0;
		}
	}
	return printf("NO\n"), 0;
}