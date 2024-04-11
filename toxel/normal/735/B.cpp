#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

int n, n1, n2, a[N];

int main(){
	scanf("%d%d%d", &n, &n1, &n2);
	if (n1 > n2){
		std::swap(n1, n2);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n, std::greater <int>());
	ll sum = 0;
	double ans = 0;
	for (int i = 0; i < n1; ++ i){
		sum += a[i];
	}
	ans += 1.0 * sum / n1;
	sum = 0;
	for (int i = n1; i < n1 + n2; ++ i){
		sum += a[i];
	}
	ans += 1.0 * sum / n2;
	return printf("%.10lf\n", ans), 0;
}