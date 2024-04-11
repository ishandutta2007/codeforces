#include<bits/stdc++.h>

const int N = 110;

int n;
int a[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	return printf(n & 1 && a[0] & 1 && a[n - 1] & 1 ? "Yes\n" : "No\n"), 0;
}