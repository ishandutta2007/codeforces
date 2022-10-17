#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n, x;
long long z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		q.push(-x);
		q.push(-x);
		z += x + q.top();
		q.pop();
	}
	printf("%lld\n", z);
	return 0;
}