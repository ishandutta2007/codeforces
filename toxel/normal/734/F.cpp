#include<bits/stdc++.h>
#define ll long long

const int N = 200010;
const int M = 40;

ll a[N], b[N], c[N], _sum[N];
ll n;

int main(){
	scanf("%I64d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &b[i]);
	}
	ll sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &c[i]);
		if (b[i] > c[i]){
			return printf("-1\n"), 0;
		}
		sum += b[i] + c[i];
	}
	if (sum % (2 * n)){
		return printf("-1\n"), 0;
	}
	sum /= 2 * n;
	for (int i = 0; i < n; ++ i){
		if ((b[i] + c[i] - sum) % n){
			return printf("-1\n"), 0;
		}
		a[i] = (b[i] + c[i] - sum) / n;
		if (a[i] < 0){
			return printf("-1\n"), 0;
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < M; ++ j){
			_sum[j] += a[i] >> j & 1;
		}
	}
	for (int i = 0; i < n; ++ i){
		ll sum1 = 0, sum2 = 0;
		for (int j = 0; j < M; ++ j){
			if (a[i] >> j & 1){
				sum1 += _sum[j] << j;
				sum2 += n << j;
			}
			else{
				sum2 += _sum[j] << j;
			}
		}
		if (sum1 != b[i] || sum2 != c[i]){
			return printf("-1\n"), 0;
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%I64d ", a[i]);
	}
	return printf("\n"), 0;
}