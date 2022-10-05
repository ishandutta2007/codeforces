#include<bits/stdc++.h>

const int N = 200010;

int n, a[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n / 2; ++ i){
		if (!(i & 1)){
			std::swap(a[i], a[n - 1 - i]);
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%d ", a[i]);
	}
	return printf("\n"), 0;
}