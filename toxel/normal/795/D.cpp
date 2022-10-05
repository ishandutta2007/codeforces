#include<bits/stdc++.h>

const int N = 100010;

int a[N], b[N], n, l, r;

int main(){
	scanf("%d%d%d", &n, &l, &r);
	-- l, -- r;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
		if (l <= i && i <= r){
			continue;
		}
		if (a[i] != b[i]){
			return printf("LIE\n"), 0;
		}
	}
	return printf("TRUTH\n"), 0;
}