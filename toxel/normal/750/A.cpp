#include<bits/stdc++.h>

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	int cnt = 0, total = 0;
	k = 240 - k;
	for (int i = 1; i <= n; ++ i){
		total += 5 * i;
		if (total <= k){
			++ cnt;
		}
		else{
			break;
		}
	}
	return printf("%d\n", cnt), 0;
}