#include<bits/stdc++.h>

const int N = 2010;

int a[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int min = INT_MAX;
	for (int i = 0; i < n; ++ i){
		if (a[i] == 1){
			min = 1;
			break;
		}
		int gcd = a[i];
		for (int j = i + 1; j < n; ++ j){
			gcd = std::__gcd(gcd, a[j]);
			if (gcd == 1){
				min = std::min(min, j - i + 1);
				break;
			}
		}
	}
	if (min == INT_MAX){
		return printf("-1\n"), 0;
	}
	if (min == 1){
		int cnt = 0;
		for (int i = 0; i < n; ++ i){
			cnt += a[i] != 1;
		}
		return printf("%d\n", cnt), 0;
	}
	return printf("%d\n", min - 1 + n - 1), 0;
}