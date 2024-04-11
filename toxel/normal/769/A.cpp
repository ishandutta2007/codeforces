#include<bits/stdc++.h>

const int N = 10;

int a[N], n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	return printf("%d\n", a[0] + a[n - 1] >> 1), 0;
}