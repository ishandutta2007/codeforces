#include<bits/stdc++.h>

typedef long long ll;

ll x, y;

int main(){
	scanf("%I64d%I64d", &x, &y);
	for (int i = 60; i >= 0; -- i){
		if ((x >> i & 1) != (y >> i & 1)){
			printf("%I64d\n", (1ll << i + 1) - 1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}