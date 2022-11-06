#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int a[100001], b[100001], s[100001];
int main() {
	int n, k;
	priority_queue<pair<long long, long long>> A, B;
	scanf("%d%d", &n, &k);
	long long S = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", s + i, a + i, b + i);
		S += s[i];
	}
	long long m = (S + k - 1) / k;

	long long ans = 0, ca=0, cb=0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= b[i]) {
			ans += 1ll * s[i] * a[i];
			ca += s[i];
			A.emplace(b[i] - a[i], s[i]);
		}
		else {
			ans += 1ll * s[i] * b[i];
			cb += s[i];
			B.emplace(a[i] - b[i], s[i]);
		}
	}
	long long ma = (ca + k - 1) / k;
	long long mb = (cb + k - 1) / k;
	if (ma + mb == m) {
		printf("%lld\n", ans);
	}
	else {
		ca %= k; cb %= k;
		long long aans = 0, t;
		
		t = 0;
		while (ca > 0) {
			t += A.top().first * min(ca, A.top().second);
			ca -= A.top().second;
			A.pop();
		}
		if (t+ans > aans) aans = t+ans;


		t = 0;
		while (cb > 0) {
			t += B.top().first * min(cb, B.top().second);
			cb -= B.top().second;
			B.pop();
		}
		if (t + ans > aans) aans = t + ans;
		printf("%lld\n", aans);
	}
	return 0;
}