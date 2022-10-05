#include<bits/stdc++.h>

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int ans = 0, ans2 = 0;
	for (int i = 0, y; i < n; ++ i){
		scanf("%d", &y);
		ans += y < x;
		ans2 += y == x;
	}
	return printf("%d\n", x - ans + ans2), 0;
}