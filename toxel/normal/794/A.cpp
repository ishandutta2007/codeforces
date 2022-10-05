#include<bits/stdc++.h>

int a, b, c, n;

int main(){
	scanf("%d%d%d%d", &a, &b, &c, &n);
	int cnt = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		if (x > b && x < c){
			++ cnt;
		}
	}
	return printf("%d\n", cnt), 0;
}