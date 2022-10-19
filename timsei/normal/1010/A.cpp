#include <bits/stdc++.h>
using namespace std;


const int N = 1005;

int A[N], B[N];

int n, m;

bool pd(double who) {
	for(int i = 1; i <= n; ++ i) {
		double now = who + m;
		double how = now / A[i];
		who -= how;
		if(who < 0) return 0;
		now = who + m;
		how = now / B[i % n + 1];
		who -= how;
		if(who < 0) return 0;
	}
	return 1;
}

main(void) {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) cin >> A[i];
	for(int i = 1; i <= n; ++ i) cin >> B[i];
	double l = 0, r = 2e9, res = -1;
	for(int i = 1; i <= 100; ++ i) {
		double mid = (l + r) * 0.5;
		if(pd(mid)) {
			res = mid; r = mid;
		}
		else l = mid;
	}
	if(res > -0.5) {
		printf("%.12lf\n", res);
	}
	else puts("-1");
}