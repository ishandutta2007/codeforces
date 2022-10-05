#include<bits/stdc++.h>
#define ll long long

const int N = 1010;
const int M = 8000000;
const int INF = 0x7f7f7f7f;

template <typename T>
T extendedeuclid(T a, T b){
	return b ? extendedeuclid(b, a % b) : a;
}

std::vector <ll> vec;
int n;
std::pair <int, ll> dp[N][N * 7];
std::pair <std::pair <int, int>, bool> pre[N][N * 7];
ll k, fac[N * 7], a[N], inv[M];

int main(){
	scanf("%d%I64d", &n, &k);
	for (ll i = 1; i * i <= k; ++ i){
		if (k % i == 0){
			vec.push_back(i);
			vec.push_back(k / i);
		}
	}
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	int cntm = 0;
	for (auto u = vec.begin(); u != vec.end(); ++ u){
		fac[u - vec.begin()] = *u;
		if (*u < M){
			++ cntm;
			inv[*u] = u - vec.begin();
		}
	}
	int cnt = vec.size();
	vec.erase(vec.begin(), std::lower_bound(vec.begin(), vec.end(), M));
	memset(dp, 0x7f, sizeof(dp));
	dp[0][0] = {0, 0};
	int max = 0, min = INF;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= max; ++ j){
			dp[i + 1][j] = dp[i][j];
			pre[i + 1][j] = {{i, j}, false};
		}
		scanf("%I64d", &a[i]);
		int sit = 0;
		for (int j = 0; j <= max; ++ j){
			if (dp[i][j].first >= min){
				continue;
			}
			ll y = extendedeuclid <ll>(a[i], k / fac[j]) * fac[j];
			int sit = y < M ? inv[y] : std::lower_bound(vec.begin(), vec.end(), y) - vec.begin() + cntm;
			max = std::max(sit, max);
			std::pair <int, ll> z = {dp[i][j].first + 1, dp[i][j].second + a[i]};
			if (z < dp[i + 1][sit]){
				dp[i + 1][sit] = z;
				pre[i + 1][sit] = {{i, j}, true};
				if (sit == cnt - 1){
					min = std::min(min, z.first);
				}
			}
		}
	}
	if (k == 1){
		ll min = LLONG_MAX, sit;
		for (int i = 0; i < n; ++ i){
			if (min > a[i]){
				min = a[i];
				sit = i;
			}
		}
		return printf("1\n%d\n", sit + 1), 0;
	}
	if (dp[n][cnt - 1].first == INF){
		return printf("-1\n"), 0;
	}
	printf("%d\n", dp[n][cnt - 1].first);
	std::pair <int, int> now = {n, cnt - 1};
	while (now.first){
		if (pre[now.first][now.second].second){
			printf("%d ", now.first);
		}
		now = pre[now.first][now.second].first;
	}
	return 0;
}