#include<bits/stdc++.h>

const int N = 110;
int n, a[N];

int main(){
	scanf("%d", &n);
	int sum = 0, sit = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
		if (sum){
			sit = i + 1;
		}
	}
	if (!sit){
		return printf("NO\n"), 0;
	}
	printf("YES\n");
	if (sum){
		return printf("1\n1 %d\n", n), 0;
	}
	return printf("2\n1 %d\n%d %d\n", sit, sit + 1, n), 0;
}