#include<bits/stdc++.h>
#define ll long long

const int N = 200010;

int n, k;
int pre[N];

int main(){
	scanf("%d%d", &n, &k);
	ll sum = 0;
	for (int i = 0; i + k <= n; ++ i){
		++ pre[i];
		-- pre[i + k];
	}
	for (int i = 1; i < n; ++ i){
		pre[i] += pre[i - 1];
	}
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		sum += 1ll * x * pre[i];
	}
	return printf("%.10lf\n", 1.0 * sum / (n - k + 1)), 0;
}