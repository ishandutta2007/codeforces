#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int a[N], suf[N];
int n;

int main(){
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
		if (i) a[i] += a[i - 1];
	}
	if (sum % 3) return printf("0\n"), 0;
	for (int i = n - 2; i >= 0; -- i){
		suf[i] = suf[i + 1] + (a[i] == sum * 2 / 3);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++ i){
		if (a[i] == sum / 3){
			ans += suf[i + 1];
		}
	}
	return printf("%I64d\n", ans), 0;
}