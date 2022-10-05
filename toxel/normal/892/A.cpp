#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int a[N], b[N];

int main(){
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
	}
	std::sort(b, b + n);
	return printf(sum <= b[n - 1] + b[n - 2] ? "YES\n" : "NO\n"), 0;
}