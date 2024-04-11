#include <iostream>

typedef long long ll;

const int ms = 100100;
const ll INF = 1e18;

ll ans = 0;
int lp = 1, rp = 0;
ll freq[ms];
int a[ms];

void go(int l, int r) {
	while(rp < r) {
		ans += freq[a[++rp]];
		freq[a[rp]]++;
	}
	while(lp > l) {
		ans += freq[a[--lp]];
		freq[a[lp]]++;
	}
	while(rp > r) {
		freq[a[rp]]--;
		ans -= freq[a[rp--]];
	}
	while(lp < l) {
		freq[a[lp]]--;
		ans -= freq[a[lp++]];
	}
	//std::cout << "on (" << lp << ", " << rp << ") got " << ans << "\n";
}


ll dp[22][ms];

void solve(int k, int l, int r, int opl, int opr) {
	if(l > r)
		return;
	int mid = (l + r) / 2;
	int cur_op;
	dp[k][mid] = INF;
	for(int i = opl; i <= std::min(mid, opr); i++) {
		go(i, mid);
		ll cur_ans = dp[k - 1][i - 1] + ans;
		if(cur_ans < dp[k][mid]) {
			dp[k][mid] = cur_ans;
			cur_op = i;
		}
	}
	solve(k, l, mid - 1, opl, cur_op);
	solve(k, mid + 1, r, cur_op, opr);
}

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		dp[0][i] = INF;
	}
	for(int i = 1; i <= k; i++) {
		solve(i, 1, n, 1, n);
	}
	std::cout << dp[k][n] << '\n';
}