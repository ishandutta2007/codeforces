#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int A[N], n, lst = 0, x, a, b, la, lb, cnt[N], B[N], tot, S[N * N];

void ask(int x) {
	printf("+ %d\n", x);
	fflush(stdout);
	++ tot;
	scanf("%d%d", &A[tot], &B[tot]);
}

int calc(int x) {
	return S[x];
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &A[0], &B[0]);
	for(int i = 2; i <= n + 1; ++ i)
	S[i * (i - 1) / 2] = i;
	for(int i = 1; i < n; ++ i) ask(i);
	ask(1);
	for(int i = n; i >= 1; -- i) A[i] -= A[i - 1], B[i] -= B[i - 1];
//	for(int i = 1; i <= n; ++ i) printf("%d %d\n", A[i], B[i]);
	
	if(!A[1] && !A[n]) {
		cnt[1] = 0;
	} else cnt[1] = calc(A[n]) - 1;
	
	int now = B[n] - B[1] - 1;
	
	if(A[2] || A[3]) {
		if(A[2]) cnt[2] = calc(A[2]), cnt[3] = now - cnt[2];
		else if(A[3]) cnt[3] = calc(A[3]), cnt[2] = now - cnt[3];
	} else {
		if(now == 2) cnt[2] = cnt[3] = 1;
		else if(now == 0) cnt[2] = cnt[3] = 0;
		else {
			if(!B[2]) {
				cnt[3] = 0;
			} else cnt[3] = 1;
			cnt[2] = 1 - cnt[3];
		}
	}
	
	for(int i = 4; i < n; ++ i) {
		if(A[i]) {
			cnt[i] = calc(A[i]);
		} else {
			if(B[i - 1] > (cnt[i - 3] + 1) * (cnt[i - 2] + 1)) {
				cnt[i] = 1;
			} else cnt[i] = 0;
		}
	}
	cnt[n] = (B[n - 1] - (cnt[n - 2] + 1) * (cnt[n - 3] + 1)) / (cnt[n - 2] + 1);
	putchar('!');
	for(int i = 1; i <= n; ++ i) {
		printf(" %d", cnt[i]);
	}
	puts("");
	fflush(stdout);
}