#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], B[N], n;

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
		vector <int> L, R;
		for(int i = 1; i <= n; i += 2) L.push_back(A[i]);
		for(int i = 2; i <= n; i += 2) R.push_back(A[i]);
		sort(L.begin(), L.end());
		sort(R.begin(), R.end());
		for(int i = 1; i <= n; i += 2) A[i] = L[i / 2];
		for(int i = 2; i <= n; i += 2) A[i] = R[(i - 1) / 2];
		bool ok = 1;
		for(int i = 1; i < n; ++ i) {
			if(A[i] <= A[i + 1] ) continue;
			else {
				ok = 0;
				puts("NO"); break;
			}
		}
		if(ok) puts("YES");
	}
}