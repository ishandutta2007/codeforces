#include<bits/stdc++.h>

typedef std::pair <int, int> pii;

const int N = 1010;

int dp[N][N];
int a[N];
int pre[N][N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	if (n == 1){
		printf("%d\n1\n", a[0]);
		return 0;
	}
	if (n == 2){
		printf("%d\n1 2\n", std::max(a[0], a[1]));
		return 0;
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0][0] = std::max(a[1], a[2]);
	dp[0][1] = std::max(a[0], a[2]);
	dp[0][2] = std::max(a[0], a[1]);
	for (int i = 0; i < n - 3 >> 1; ++ i){
		for (int j = 0; j <= i + 1 << 1; ++ j){
			int x = dp[i][j] + std::max(a[i + 1 << 1 | 1], a[i + 2 << 1]);
			if (dp[i + 1][j] > x){
				dp[i + 1][j] = x;
				pre[i + 1][j] = j;
			}
			x = dp[i][j] + std::max(a[j], a[i + 2 << 1]);
			if (dp[i + 1][i + 1 << 1 | 1] > x){
				dp[i + 1][i + 1 << 1 | 1] = x;
				pre[i + 1][i + 1 << 1 | 1] = j;
			}
			x = dp[i][j] + std::max(a[i + 1 << 1 | 1], a[j]);
			if (dp[i + 1][i + 2 << 1] > x){
				dp[i + 1][i + 2 << 1] = x;
				pre[i + 1][i + 2 << 1] = j;
			}
		}
	}
	std::vector <pii> ans;
	int min = INT_MAX, sit;
	if (n & 1){
		for (int i = 0; i < n; ++ i){
			if (min > dp[n - 3 >> 1][i] + a[i]){
				min = dp[n - 3 >> 1][i] + a[i];
				sit = i;
			}
		}
		ans.push_back({sit, -1});
		int now = n - 3 >> 1;
		while (now >= 0){
			int x1 = now << 1 | 1, x2 = now + 1 << 1;
			if (sit == x1){
				ans.push_back({pre[now][sit], x2});
			}
			else if (sit == x2){
				ans.push_back({pre[now][sit], x1});
			}
			else{
				ans.push_back({x1, x2});
			}
			sit = pre[now][sit];
			-- now;
		}
	}
	else{
		for (int i = 0; i < n - 1; ++ i){
			if (min > dp[n - 3 >> 1][i] + std::max(a[i], a[n - 1])){
				min = dp[n - 3 >> 1][i] + std::max(a[i], a[n - 1]);
				sit = i;
			}
		}
		ans.push_back({sit, n - 1});
		int now = n - 3 >> 1;
		while (now >= 0){
			int x1 = now << 1 | 1, x2 = now + 1 << 1;
			if (sit == x1){
				ans.push_back({pre[now][sit], x2});
			}
			else if (sit == x2){
				ans.push_back({pre[now][sit], x1});
			}
			else{
				ans.push_back({x1, x2});
			}
			sit = pre[now][sit];
			-- now;
		}
	}
	printf("%d\n", min);
	std::reverse(ans.begin(), ans.end());
	for (auto u : ans){
		if (u.second == -1){
			printf("%d\n", u.first + 1);
		}
		else{
			printf("%d %d\n", u.first + 1, u.second + 1);
		}
	}
	return 0;
}