#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, C;

long long d[N];

int main() {
	scanf("%d%d", &n, &C);
	for(int i = 1; i <= n; ++ i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		d[a] = max(d[a], 1LL * b * c);
	}
	for(int i = 1; i <= C; ++ i) {
		for(int j = i; j <= C; j += i) 
		d[j] = max(d[j], d[i] * (j / i));
	}
	for(int i = 1; i <= C; ++ i) d[i] = max(d[i], d[i - 1]);
	scanf("%d", &m);
	for(int i = 1; i <= m; ++ i) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		a = a * b + 1;
		int l = 0, r = C, res = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(d[mid] < a) {
				l = mid + 1;  
			} else {
				res = mid; r = mid - 1;
			}
		}
		printf("%d ", res);
	}
	puts("");
}