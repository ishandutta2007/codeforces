#include<bits/stdc++.h>

const int N = 200010;

int a[N], n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; ++ i){
		if (a[i] & 1){
			if (!a[i + 1]){
				return printf("NO\n"), 0;
			}
			-- a[i + 1];
		}
	}
	return printf(a[n - 1] & 1 ? "NO\n" : "YES\n"), 0;
}