#include<bits/stdc++.h>

const int N = 110;

int a[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++ i){
		for (int j = i; j < n; ++ j){
			bool flag = true;
			for (int k = 0; k < i; ++ k){
				if (a[k] >= a[k + 1]){
					flag = false;
				}
			}
			for (int k = i + 1; k <= j; ++ k){
				if (a[k] != a[i]){
					flag = false;
				}
			}
			for (int k = j + 1; k < n; ++ k){
				if (a[k - 1] <= a[k]){
					flag = false;
				}
			}
			if (flag){
				return printf("YES\n"), 0;
			}
		}
	}
	return printf("NO\n"), 0;
}