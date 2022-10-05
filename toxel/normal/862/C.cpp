#include<bits/stdc++.h>

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	if (!x && n % 4 == 2){
		if (n == 2) return printf("NO\n"), 0;
		printf("YES\n1 2 3 4 8 12");
		for (int i = 0, sz = n - 6 >> 2; i < sz; ++ i){
			printf(" %d %d %d %d", 999999 - (i << 2), 999998 - (i << 2), 999997 - (i << 2), 999996 - (i << 2));
		}
		return printf("\n"), 0;
	}
	printf("YES\n");
	if (n % 4 == 1){
		printf("%d", x);
	}
	else if (n % 4 == 2){
		printf("%d %d", x ^ 1 << 17, 1 << 17);
	}
	else if (n % 4 == 3){
		printf("%d %d %d", x ^ 1 << 18, 3 << 17, 1 << 17);
	}
	else{
		printf("%d %d %d %d", x, 3 << 17, 2 << 17, 1 << 17);
	}
	for (int i = 0, sz = n - 1 >> 2; i < sz; ++ i){
        printf(" %d %d %d %d", 999999 - (i << 2), 999998 - (i << 2), 999997 - (i << 2), 999996 - (i << 2));
	}
	return printf("\n"), 0;
}