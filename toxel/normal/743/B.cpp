#include<bits/stdc++.h>
#define ll long long

int main(){
	ll n, k;
	scanf("%I64d%I64d", &n, &k);
	int ans = 1;
	while (!(k & 1)){
		k >>= 1;
		++ ans;
	}
	printf("%d\n", ans);
	return 0;
}