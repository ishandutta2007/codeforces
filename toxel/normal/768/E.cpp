#include<bits/stdc++.h>

const int N = 100;
int s[N] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int main(){
	int n;
	scanf("%d", &n);
	int ret = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		ret ^= s[x];
	}
	return printf(ret ? "NO\n" : "YES\n"), 0;
}