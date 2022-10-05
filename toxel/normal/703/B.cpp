#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

int n, k;
int c[N];
bool capital[N];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &c[i]);
	}
	for (int i = 0, x; i < k; ++ i){
		scanf("%d", &x);
		capital[x] = true;
	}
	ll sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 1; i <= n; ++ i){
		capital[i] ? (sum1 += c[i], sum2 += c[i] * c[i]): sum3 += c[i];
	}
	ll ans = sum1 * sum1 - sum2 >> 1;
	ans += sum1 * sum3;
	for (int i = 1; i <= n; ++ i){
		if (!capital[i] && !capital[i % n + 1]){
			ans += c[i] * c[i % n + 1];
		}
	}
	return printf("%I64d\n", ans), 0;
}