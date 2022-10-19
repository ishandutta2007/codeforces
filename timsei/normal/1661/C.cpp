#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, x, A[N], t, B[N];
long long Sum;

long long calc(long long x) {
	if(x % 3 == 0) return x / 3 * 2;
	if(x % 3 == 1) return x / 3 * 2 + 1;
	else return x / 3 * 2 + 2;
}

bool pd(long long T) {
	long long a = (T + 1) / 2, b = T / 2;
	for(int i = 1; i <= n; ++ i) {
		B[i] = A[i];
		int cur = min(b, (long long) B[i] / 2);
		B[i] -= cur * 2;
		b -= cur;
		a -= B[i];
	}
	return (a >= 0) && (b >= 0);
}

long long solve(int cur) {
	Sum = 0;
	for(int i = 1; i <= n; ++ i) 
	A[i] += cur, Sum += A[i];
	long long l = 0, r = 1e16, res = -1;
	while(l <= r) {
		long long mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid; r = mid - 1;
		} else l = mid + 1;
	}
	
	return res;
}

void rmain() {
	scanf("%d", &n);
	Sum = 0;
	int mx = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
		Sum += A[i];
		mx = max(mx, A[i]);
	}
	priority_queue < int > q;
	for(int i = 1; i <= n; ++ i) {
		A[i] = mx - A[i];
	}
	if(!Sum) {
		puts("0");
		return;
	}
	long long ans = solve(0);
	ans = min(ans, solve(1));
	ans = min(ans, solve(1));
	printf("%lld\n", ans);
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}