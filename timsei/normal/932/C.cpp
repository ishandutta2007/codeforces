#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n , a , b;

void print(int x , int y) {
	for(int i = 1;i <= x * a;i += a) {
		for(int j = i;j <= i + a - 2;++ j) {
			printf("%d " , j + 1);
		}
		printf("%d " , i);
	}
	for(int i = x * a + 1;i <= n;i += b) {
		for(int j = i;j <= i + b - 2;++ j) {
			printf("%d " , j + 1);
		}
		printf("%d " , i);
	}
}

main(void) {
	cin >> n >> a >> b;
	for(int i = 0;i <= n / a;++ i) {
		int it = n - i * a;
		if(it % b == 0) {
			print(i , it / b);
			return 0;
		}
	}
	puts("-1");
}