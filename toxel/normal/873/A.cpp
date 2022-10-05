#include<bits/stdc++.h>

const int N = 110;

int a[N];
int n, k, x;

int main(){
	scanf("%d%d%d", &n, &k, &x);
	int sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += i + k < n ? a[i] : x;
	}
	return printf("%d\n", sum), 0;
}