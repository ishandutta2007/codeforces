#include<bits/stdc++.h>

const int N = 1000;

int a[N], k;

int main(){
	for (int i = 0; i < N; ++ i){
		a[i] = i * (i - 1) >> 1;
	}
	int now = 0;
	scanf("%d", &k);
	if (!k){
		return printf("a\n"), 0;
	}
	while (k > 0){
		int sit = std::upper_bound(a, a + N, k) - a - 1;
		for (int i = 0; i < sit; ++ i){
			putchar('a' + now);
		}
		++ now;
		k -= a[sit];
	}
	putchar('\n');
	return 0;
}