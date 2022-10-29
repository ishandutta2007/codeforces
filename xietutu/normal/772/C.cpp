#include <bits/stdc++.h>

using namespace std;

const int maxn=200005;
int n, m, a[maxn], g[maxn], h[maxn], num;
vector<int> F[maxn];
vector<int> ans;
set<int> S;

typedef long long LL;
LL extend_gcd(LL a, LL b, LL& x, LL& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	else {
		LL r = extend_gcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

void dfs(int X) {
	if (h[X] != 0) dfs(h[X]);	
	for (int i = 0; i < F[X].size(); ++i) {
		long long x, y; 
		extend_gcd(num, m, x, y);
		int k = __gcd(num, m);
		x = x * F[X][i] / k;
		x = (x % (m / k) + m / k) % m;
		ans.push_back(x);
		num = F[X][i];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		S.insert(a[i]);
	}
	for (int i = 1; i <= m - 1; ++i) 
	if (S.find(i)==S.end()){
		int k = __gcd(i, m);
		F[k].push_back(i);
	}
	int mm = 0, mn = 0;
	for (int i = 1; i < m; ++i) {
		if (i != 1)
		for (int j = 1; j * j <= i; ++j) 
		if (i % j == 0) {
			if (g[j] > g[i]) {
				g[i] = g[j];
				h[i] = j;
			}
			if (j != 1 && g[i / j] > g[i]) {
				g[i] = g[i / j];
				h[i] = i / j;
			}
		}
		g[i] += F[i].size();
		if (g[i] > mm) {
			mm = g[i];
			mn = i;
		}
	}
	num = 1;
	if (mn != 0) dfs(mn);
	if (S.find(0) == S.end()) ans.push_back(0);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", ans[i]);
		if (i != ans.size() - 1) printf(" ");
		else puts("");
	}
	return 0;
}