#include<bits/stdc++.h>
#define ll long long

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	ll cnt = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		cnt += (x + k - 1) / k;
	}
	return printf("%I64d\n", cnt + 1 >> 1), 0;
}