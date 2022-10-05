#include<bits/stdc++.h>

const int N = 100;

int n;

int main(){
	scanf("%d", &n);
	int max = 0, x;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &x);
		max = std::max(max, x);
	}
	return printf("%d\n", x ^ max), 0;
}