#include<bits/stdc++.h>

const int N = 1010;

int n, k;
int a[N];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		while (k << 1 < a[i]){
			++ ans;
			k <<= 1;
		}
		k = std::max(k, a[i]);
	}
	return printf("%d\n", ans), 0;
}