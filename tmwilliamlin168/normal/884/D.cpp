#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> h;


int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		h.push(-x);
	}
	long long ans = 0;
	if (h.size() % 2 == 0) {
		long long a = h.top();
		h.pop();
		long long b = h.top();
		h.pop();
		long long sum = a + b;
		ans -= sum;
		h.push(sum);
	};
	while (h.size() > 1) {
		long long a = h.top();
		h.pop();
		long long b = h.top();
		h.pop();
		long long c = h.top();
		h.pop();
		long long sum = a + b + c;
		ans -= sum;
		h.push(sum);
	}
	printf("%I64d\n",ans);
}