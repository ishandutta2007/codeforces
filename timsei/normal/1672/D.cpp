#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int S[N], n, tmp[N];

int A[N], B[N];

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]);
	multiset <int> S;
	int j = n;
	for(int i = n; i >= 1; -- i) {
		if(B[j] != A[i] || !j) {
			if(S.find(A[i]) == S.end()) {
				puts("NO");
				return;
			} else {
				S.erase(S.find(A[i]));
				continue;
			}
		} else {
			int now = B[j];
			while(j >= 2 && B[j - 1] == now) {
				S.insert(now);
				-- j;
			}
			-- j;
		}
	}
	puts("YES");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}