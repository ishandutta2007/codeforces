#include<bits/stdc++.h>

const int N = 100010;

int n, a[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	int ans = n;
	for (int i = 0; i < n; ++ i){
		if (a[i] == a[0] || a[i] == a[n - 1]){
			-- ans;
		}
	}
	return printf("%d\n", ans), 0;
}