#include<bits/stdc++.h>

const int N = 110;

int a[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n, std::greater <int>());
	int i;
	for (i = 0; m > 0; ++ i){
		m -= a[i];
	}	
	return printf("%d\n", i), 0;
}