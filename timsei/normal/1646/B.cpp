#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e6 + 5;

int n, s, t, A[N];

main() {
	for(cin >> t; t --;) {
		scanf("%lld", &n);
		for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
		sort(A + 1, A + n + 1);
		int SB = A[1], l = 2, r = n, SA = 0;
		for(int i = 1; i + i + 1 <= n; ++ i) {
			SB += A[l];
			SA += A[r];
			++ l, -- r;
			if(SA > SB) {
				puts("YES");
				break;
			}
		}
		if(SA <= SB) puts("NO");
		
	}
}