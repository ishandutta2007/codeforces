#include<bits/stdc++.h>

int a;

int main(){
	scanf("%d", &a);
	if (a <= 2){
		return printf("-1\n"), 0;
	}
	int left = 1;
	while (!(a & 1)){
		a >>= 1;
		left <<= 1;
	}
	if (a == 1){
		long long b = 1ll * (left >> 1) * (left >> 1) - 1, c = b + 2;
		return printf("%I64d %I64d\n", b, c), 0;
	}
	int r = a + 1 >> 1, s = a - 1 >> 1;
	long long b = 1ll * r * s << 1, c = 1ll * r * r + 1ll * s * s;
	a *= left, b *= left, c *= left;
	return printf("%I64d %I64d\n", b, c), 0;
}