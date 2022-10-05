#include<bits/stdc++.h>

const int N = 100010;

int a[N], n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	for (int i = n - 1; i >= 2; -- i){
		if (a[i] < a[i - 1] + a[i - 2]){
			return printf("YES\n"), 0;
		}
	}
	return printf("NO\n"), 0;
}