#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int n, m, x, y, A[N], ans, B[N];

main() {
	int ttt;
	for(cin >> ttt; ttt --;) {
		scanf("%lld%lld", &n, &m);
		swap(n, m);
		
		for(int i = 0; i <= n * m + 1; ++ i) A[i] = B[i] = 0;
		
		int id = 0, who = 1;
		
		for(int i = 1; i <= m; ++ i) {
			for(int j = 1; j <= n; ++ j) scanf("%lld", &A[(i - 1) * n + j])
			, B[i] += 1LL * j * A[(i - 1) * n + j];
			if(B[i] > B[id]) id = i;
		}
		if(id == 1) who = 2;
		
		printf("%lld %lld\n", id, B[id] - B[who]);
		
	}
}