#include <bits/stdc++.h>
using namespace std;
int n, x;
long long ans;
priority_queue<int> q;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		q.push(-x);
		q.push(-x);
		ans += x + q.top();
		q.pop();
	}
	printf("%lld\n", ans);
	return 0;
}