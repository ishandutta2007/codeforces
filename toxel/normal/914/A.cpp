#include<bits/stdc++.h>

int sqrt(int x){
	if (x < 0) return -1;
	if (x == 0) return 0;
	int y = std::max(std::sqrt(x) - 5, 0.0);
	while (y * y < x){
		++ y;
	}
	return y;
}

int main(){
	int n;
	scanf("%d", &n);
	int max = INT_MIN;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		int y = sqrt(x);
		if (y < 0 || y * y != x){
			max = std::max(max, x);
		}
	}
	return printf("%d\n", max), 0;
}