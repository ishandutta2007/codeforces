#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int A[N], B[N], n, m;
long long S1[N], S2[N];

int L[N], R[N];

void print(int l1, int l2, int r1, int r2, int ok) {
	if(!ok) swap(l1, r1), swap(l2, r2);
	
	printf("%d\n", l2 - l1 + 1);
	for(int i = l1; i <= l2; ++ i) printf("%d ", i);
	puts("");
	printf("%d\n", r2 - r1 + 1);
	for(int i = r1; i <= r2; ++ i) printf("%d ", i);
	puts("");
	exit(0);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), S1[i] = S1[i - 1] + A[i];
	for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]), S2[i] = S2[i - 1] + B[i];
	bool ok = (S1[n] < S2[n]);
	if(!ok)
	for(int i = 1; i <= n; ++ i) swap(S1[i], S2[i]), swap(A[i], B[i]);
	for(int i = 1; i <= n; ++ i) {
		if(S1[i] == S2[i]) {
			printf("%d\n", i);
			for(int j = 1; j <= i; ++ j) printf("%d ", j);
			puts("");
			printf("%d\n", i);
			for(int j = 1; j <= i; ++ j) printf("%d ", j);
			puts("");
			return 0;			
		}
		int l = 0, r = n, res = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(S2[mid] <= S1[i]) {
				res = mid; l = mid + 1;
			} else r = mid - 1;
		}
		if(S1[i] == S2[res]) {
			print(1, i, 1, res, ok);
		} else {
			int cur = S1[i] - S2[res];
			if(L[cur]) {
				print(L[cur] + 1, i, R[cur] + 1, res, ok);
			} else L[cur] = i, R[cur] = res;
		}
	}
}