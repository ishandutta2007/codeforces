#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], B[N], id[N], n, m;

bool cmp(int x, int y) {
	return A[x] > A[y];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) id[i] = i;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]);
	sort(id + 1, id + n + 1, cmp);
	int cnt = n / 2 + 1;
	printf("%d\n", n / 2 + 1);
	printf("%d ", id[1]);
	for(int i = 2; i <= n; i += 2) {
		if(i == n) {
			printf("%d ", id[n]);
			return 0;
		} else {
			if(B[id[i]] > B[id[i + 1]]) printf("%d ", id[i]);
			else printf("%d ", id[i + 1]);
		}
	}
}