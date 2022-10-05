#include<bits/stdc++.h>

const int N = 10010;

int n, m, d;
int a[N];

int main(){
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n * m; ++ i){
		scanf("%d", &a[i]);
		if (i && (a[i] - a[i - 1]) % d){
			return printf("-1\n"), 0;
		}
	}
	std::sort(a, a + n * m);
	int sum = 0;
	for (int i = 0; i < n * m; ++ i){
		sum += std::abs(a[i] - a[n * m >> 1]);
	}
	return printf("%d\n", sum / d), 0;
}