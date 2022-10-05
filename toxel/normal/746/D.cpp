#include<bits/stdc++.h>

int n, a, b, k;

void solve(char c1, char c2){
	if (a < b){
		std::swap(a, b);
	}
	int x = (a + k - 1) / k;
	if (x > b + 1){
		printf("NO\n");
		exit(0);
	}
	int y = b % x;
	for (int i = 0; i < x; ++ i){
		if (i != x - 1 || !(a % k)){
			for (int j = 0; j < k; ++ j){
				putchar(c1);
			}
		}
		else{
			for (int j = 0; j < a % k; ++ j){
				putchar(c1);
			}
		}
		if (i >= y){
			for (int j = 0; j < b / x; ++ j){
				putchar(c2);
			}
			
		}
		else{
			for (int j = 0; j < b / x + 1; ++ j){
				putchar(c2);
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d", &n, &k, &a, &b);
	if (a >= b){
		solve('G', 'B');
	}
	else{
		solve('B', 'G');
	}
	return 0;
}