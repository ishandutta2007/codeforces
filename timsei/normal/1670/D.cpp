#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n, A[N], B[N], vis[N], tot, ans, where[N], ok[N], D[N];

int dfs(int i) {
	if(vis[i]) return ok[i];
	vis[i] = 1;
	int now = dfs(where[B[i]]);
	if(now == -1) return -1;
	if(!now || !ok[i])
	return ok[i] + now;
	else {
		if(now == ok[i]) return now;
		else return -1;
	}
}

long long calc(int t) {
	int now = t / 3;
	int a = now, b = now, c = now;
	t %= 3;
	if(t >= 1) ++ a;
	if(t >= 2) ++ b;
	return 2LL * a * b + 2LL * b * c + 2LL * a * c;
}

void rmain() {
	scanf("%d", &n);
	int l = 0, r = 1e5, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(calc(mid) >= n) {
			res = mid; r = mid - 1;
		} else l = mid + 1;
	}
	cout << res << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}