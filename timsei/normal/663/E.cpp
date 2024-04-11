#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5e5;

int n , m , A[N] , B[N];
char s[22][111111];

#define lowbit(x) (x & (-x))

int bc(int x) {
	int res = 0;
	for(;x;x -= lowbit(x)) ++ res;
	return res;
}

void DWT(int *A) {
	for(int i = 0;i < n;++ i) {
		for(int j = 0;j < (1 << n);j += (1 << (i + 1))) {
			for(int k = j;k < (j + (1 << i));++ k) {
				int u = A[k] + A[k + (1 << i)] ,
				v = A[k] - A[k + (1 << i)];
				A[k] = u; A[k + (1 << i)] = v;
			}
		}
	}
}

void IDWT(int *A) {
	for(int i = 0;i < n;++ i) {
		for(int j = 0;j < (1 << n);j += (1 << (i + 1))) {
			for(int k = j;k < (j + (1 << i));++ k) {
				int u = (A[k] + A[k + (1 << i)]) / 2 , v = (A[k] - A[k + (1 << i)]) / 2;
				A[k] = u; A[k + (1 << i)] = v;
			}
		}
	}
}

main() {
	scanf("%lld%lld" , &n , &m);
	for(int i = 1;i <= n;++ i) {
		scanf("%s" , s[i] + 1);
	}
	int MAX = (1 << n);
	for(int i = 0;i < MAX;++ i)
	A[i] = min(bc(i) , bc(MAX - 1 - i));
	for(int i = 1;i <= m;++ i) {
		int mask = 0;
		for(int j = 1;j <= n;++ j) {
			mask = mask | ((1 << (j - 1)) * (s[j][i] - '0'));
		}
		++ B[mask];
	}
	DWT(A);
	DWT(B);
	for(int i = 0;i < MAX;++ i)
	A[i] = A[i] * B[i];
	IDWT(A);
	int res = 2e9;
	for(int i = 0;i < MAX;++ i) {
		res = min(res , A[i]);
	}
	cout << res << endl;
}