#include<bits/stdc++.h>

const int N = 100010;

int cnt[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	for (int i = 0; i < N; ++ i){
		if (cnt[i] & 1){
			puts("Conan");
			return 0;
		}
	}
	puts("Agasa");
	return 0;
}