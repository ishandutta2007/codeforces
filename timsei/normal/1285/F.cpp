#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> G[N], K[N];

int A[N], n, cnt[N], tot, mu[N], pr[N];
bitset < N > isp;

void prework(int n) {
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; j += i) G[j].push_back(i);
	}
	for(int i = 2; i <= n; ++ i) isp[i] = 1;
	mu[1] = 1;
	for(int i = 2; i <= n; ++ i) {
		if(isp[i]) {
			mu[i] = -1;
			pr[++ tot] = i;
		}
		for(int j = 1; j <= tot && pr[j] * i <= n; ++ j) {
			isp[i * pr[j]] = 0;
			mu[i * pr[j]] = mu[i] * mu[pr[j]];
			if(i % pr[j] == 0) {
				mu[i * pr[j]] = 0; break;
			}
		}
	}
}

int B[N], clk;

long long solve(int d) {
	long long ans = 0;
	reverse(K[d].begin(), K[d].end());
	vector <int> h;
	for(auto x : K[d])  {
		int res = 0;
		++ clk;
		for(auto g : G[x]) {
			B[g] = clk;
			res += mu[g] * cnt[g];
		}
		while(res > 0) {
			int cur = h.back();
			h.pop_back();
			int pp = res;
			for(auto g : G[cur]) {
				if(B[g] == clk) {
					res -= mu[g];
				}
				-- cnt[g];
			}
			if(res < pp) {
				ans = max(ans, 1LL * x * cur);
			}
		}
		h.push_back(x);
		for(auto g : G[x]) {
			++ cnt[g];
		}
	}
	for(int i = 0; i < (int) h.size(); ++ i) {
		for(auto g : G[h[i]]) -- cnt[g];
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	prework(100000);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= n; ++ i) {
		for(auto g : G[A[i]]) {
			K[g].push_back(A[i] / g);
		}
	}
	
	long long ans = 0;
	
	for(int d = 1; d <= 100000; ++ d) {
		ans = max(ans, 1LL * d * solve(d));
	}
	cout << ans << endl;
}