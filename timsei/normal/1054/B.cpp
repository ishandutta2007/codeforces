#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], n;

int main() {
	cin >> n;
	int cur = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
		if(A[i] < cur) continue;
		if(A[i] == cur) cur ++;
		else {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
}