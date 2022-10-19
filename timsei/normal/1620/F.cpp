#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int n, A[N], P[N], f[N];

void solve() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i)
	scanf("%d", &A[i]);
	for(int i = 1; i < 2 * n; ++ i)
    P[i] = -1, f[i] = n + 1;
	f[0] = f[1] = -n;
	for(int i = 1; i < n; ++ i) 
		for(int x = 0; x < 2; ++ x) 
			for(int y = 0; y < 2; ++ y) {
    		int v[2] = {f[i * 2 - 2 + y], A[i - 1] * (2 * y - 1)};
    		for(int j = 0; j < 2; ++ j)
		 	if(v[j] <= A[i] * (2 * x - 1) && v[(j == 0)] < f[i * 2 + x])
      		f[i * 2 + x] = v[!j], P[i * 2 + x] = i * 2 - 2 + y;
  	}
	if(f[2 * n - 1] <= n) {
    	puts("YES");
    	for(int i = n - 1, x = 2 * n - 1; ~i; -- i, x = P[x])
		if (x % 2 == 0) A[i] *= -1;
		for(int i = 0; i < n; ++ i)
		printf("%d ", A[i]);
    	puts("");
	} else {
		puts("NO");
	}
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--)
    solve();
  return 0;
}