#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int n, m, x, y, A[N], ans;

main() {
	int ttt;
	for(cin >> ttt; ttt --;) {
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= m; ++ i) scanf("%lld", &A[i - 1]);
		sort(A, A + m);
		vector <int> all;
		for(int i = 1; i < m; ++ i) all.push_back(A[i] - A[i - 1] - 1);
		all.push_back(n - A[m - 1] + A[0] - 1);
		sort(all.begin(), all.end());
		reverse(all.begin(), all.end());
		int tot = 0, day = 0;
		for(int i = 0; i < (int) all.size(); ++ i) {
			if(all[i] - day * 2 <= 0) continue;
			else {
				int cur = all[i] - day * 2;
				if(cur <= 2) {
					++ tot, ++ day; continue;
				} else {
					day += 2;
					tot += cur - 1;
				}
			}
		}
		printf("%lld\n", n - tot);
	}
}