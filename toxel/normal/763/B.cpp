#include<bits/stdc++.h>

const int N = 500010;

int n;

int main(){
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 0, a, b, c, d; i < n; ++ i){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = std::min(a, c), y = std::min(b, d);
		printf("%d\n", ((x & 1) << 1 | (y & 1)) + 1);
	}
	return 0;
}