#include<bits/stdc++.h>

int n, a, b;

int main(){
	scanf("%d%d%d", &n, &a, &b);
	int c = 0;
	int ans = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		if (x == 1){
			if (a){
				-- a;
			}
			else if (b){
				-- b;
				++ c;
			}
			else if (c){
				-- c;
			}
			else{
				++ ans;
			}
		}
		else{
			if (b){
				-- b;
			}
			else{
				ans += 2;
			}
		}
	}
	return printf("%d\n", ans), 0;
}