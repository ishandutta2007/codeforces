#include<bits/stdc++.h>

int a, b, f, k;

int main(){
	scanf("%d%d%d%d", &a, &b, &f, &k);
	if (b < f){
		return printf("-1\n"), 0;
	}
	int now = b - f, ans = 0, dir = 1;
	for (int i = 0; i < k; ++ i, dir ^= 1){
        int dis = (dir ? a - f : f) << (i == k - 1 ? 0 : 1);
        if (now < dis){
			++ ans;
			now = b - dis;
			if (now < 0){
				return printf("-1\n"), 0;
			}
		}
		else{
			now -= dis;
		}
	}
	return printf("%d\n", ans), 0;
}