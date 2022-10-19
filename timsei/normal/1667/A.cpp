#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int n, m, x, y, A[N];

long long solve(int x) {
	long long cur = 1, ans = 0, who;
	for(int i = x + 1; i <= n; ++ i) {
		who = (cur - 1) / A[i] + 1;
		ans += who;
		cur = who * A[i] + 1;
	}
	
	cur = 1, who = 0;
	
	for(int i = x - 1; i >= 1; -- i) {
		who = (cur - 1) / A[i] + 1;
		ans += who;
		cur = who * A[i] + 1;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	long long ans = 1e18;
	for(int i = 1; i <= n; ++ i) {
		ans = min(ans, solve(i));
	}
	cout << ans << endl;
}