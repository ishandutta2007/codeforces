#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int m, n, hp[N], A[N], B[N], C[N], tot;

int main() {
	cin >> n >> m;
	int Sum = 0, tot = 0;
	vector <int> ans; ans.clear();
	for(int i = 1; i <= m; ++ i) {
		scanf("%d", &A[i]);
		while(A[i] >= n) {
			for(int j = 0; j < m; ++ j) ans.push_back(i);
			A[i] -= n;
			continue;
		}
		C[++ tot] = (Sum += A[i]) % n;
	}
	-- tot;
	C[++ tot] = 0; C[++ tot] = n;
	sort(C + 1, C + tot + 1);
	for(int i = 1; i < tot; ++ i)
	C[i] = C[i + 1] - C[i];
	int now = 1;
	for(int i = 1; i <= m; ++ i) {
		while(A[i] > 0) {
			A[i] -= C[now];
			ans.push_back(i);
			++ now;
			if(now == m + 1) now -= m;
		}
	}
	while(ans.size() % m) ans.push_back(1);
	cout << ans.size() / m << endl;
	for(int i = 1; i <= m; ++ i) printf("%d ", C[i]);
	puts("");
	for(int i = 0; i < (int) ans.size(); ++ i) {
		printf("%d ", ans[i]);
		if(i % m == m - 1) puts("");
	}
}