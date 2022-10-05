#include<bits/stdc++.h>

const int N = 100010;
const int M = 25;
typedef long long ll;

ll dp[M][N];
int cnt[N], a[N];
ll cost, left, right;

void move(int nleft, int nright){
	while (nleft < left) cost += cnt[a[-- left]] ++;
	while (nright > right) cost += cnt[a[++ right]] ++;
	while (nleft > left) cost -= -- cnt[a[left ++]];
	while (nright < right) cost -= -- cnt[a[right --]];
}

void solve(int type, int l, int r, int opl, int opr){
	if (l > r) return;
	ll mincost = LLONG_MAX;
	int mid = l + r >> 1, sit;
	for (int i = opl, sz = std::min(opr, mid - 1); i <= sz; ++ i){
		move(i + 1, mid);
		ll x = dp[type - 1][i] + cost;
		if (x < mincost){
			mincost = x;
			sit = i;
		}
	}
	dp[type][mid] = mincost;
	solve(type, l, mid - 1, opl, sit);
	solve(type, mid + 1, r, sit, opr);
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	left = 1, right = 0;
	move(1, n);
	memset(dp[0], 0x3f, sizeof(dp[0]));
	dp[0][0] = 0;
	for (int i = 1; i <= k; ++ i){
		solve(i, 1, n, 0, n);
	}
	return printf("%I64d\n", dp[k][n]), 0;
}