#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int A[N], B[4], n;

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		puts("1");
		for(int i = 2; i <= n; ++ i) { {
				printf("1 ");
				for(int j = 2; j < i; ++ j) printf("0 ");
				puts("1");
			}
		}
	}
}