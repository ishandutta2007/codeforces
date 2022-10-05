#include<bits/stdc++.h>

const int N = 100010;

int a[N], b[N];
int n;

int main(){
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; ++ i){
		b[i] = sum / n + (i < sum % n);
	}
	std::sort(b, b + n);
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		ans += std::abs(a[i] - b[i]);
	}
	return printf("%d\n", ans >> 1), 0;
}