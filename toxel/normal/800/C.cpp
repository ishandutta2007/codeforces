#include<bits/stdc++.h>

const int N = 200010;

std::vector <int> prime, vec[N], ans;
std::set <int> fact;
int n, m;
bool vis[N];
int dp[N], min[N], pre[N];

int extended_euclid(int a, int b, int &x, int &y){
	int p;
	if (b){
		int ret = extended_euclid(b, a % b, x, y);
		p = y, y = x - a / b * y, x = p;
		return ret;
	}
	x = 1, y = 0;
	return a;
}

int inv(int a, int moder){
	int x, y;
	int ret = extended_euclid(a, moder, x, y);
	if (ret != 1){
		return -1;
	}
	return (x + moder) % moder;
}

int main(){
	for(int i = 2; i < N; ++ i){
		if(!min[i]){
			prime.push_back(i);
			min[i] = i;
		}
		for(int j = 0, k, sz = (int)(prime.size()); j < sz && i * prime[j] < N; ++ j){
			min[k = i * prime[j]] = prime[j];
			if(i % prime[j] == 0){
				break;
			}
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		if (!x){
			x += m;
		}
		vis[x] = true;
	}
	for (int i = 1; i <= m; ++ i){
		if (!vis[i]){
			vec[std::__gcd(i, m)].push_back(i);
		}
	}
	int x = m;
	while (x > 1){
		fact.insert(min[x]);
		x /= min[x];
	}
	memset(dp, -1, sizeof(dp));
	dp[1] = vec[1].size();
	for (int i = 1; i <= m; ++ i){
		if (dp[i] == -1){
			continue;
		}
		for (auto u : fact){
			int x = u * i;
			if (m % x){
				continue;
			}
			int y = dp[i] + vec[x].size();
			if (y > dp[x]){
				dp[x] = y;
				pre[x] = i;
			}
		}
	}
	printf("%d\n", dp[m]);
	int now = m;
	while (now){
		if (vec[now].size()){
			ans.push_back(now);
		}
		now = pre[now];
	}
	std::reverse(ans.begin(), ans.end());
	now = 1;
	for (auto u : ans){
		for (auto v : vec[u]){
			int x = std::__gcd(now, m);
			int y = inv(now / x, m / x);
			printf("%I64d ", 1ll * y * (v / x) % m);
			now = v;
		}
	}
	return printf("\n"), 0;
}