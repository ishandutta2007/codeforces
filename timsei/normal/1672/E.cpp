#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
 
int S[N], n, tmp[N];
 
int A[N], B[N], l, r;
 
int ask(int x) {
    if(!x) return 0;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
 
void rmain() {
	scanf("%d", &n);
	int L = n, R = 2001 * n, res = -1;
	while(L <= R) {
		int mid = (L + R) >> 1;
		if(ask(mid) != 1) {
			L = mid + 1;
		} else {
			res = mid; R = mid - 1;
		}
	}
	int w = res, h = 1;
	for(int i = 2; i <= n; ++ i) {
		int now = res - res % i;
		if(now == res) now -= i;
		if(ask(now / i) == i) {
			if(now < w * h) {
				w = now / i, h = i;
			}
		}
	}
	printf("! %d\n", w * h);
	fflush(stdout);
}
 
int main() {
	int t;
	for(t = 1; t --;) {
		rmain();
	}
}