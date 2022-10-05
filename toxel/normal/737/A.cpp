#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int c[N], v[N], g[N];
int main(){
	int n, k, s, t;
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &c[i], &v[i]);
	}
	for (int i = 1; i <= k; ++ i){
		scanf("%d", &g[i]);
	}
	std::sort(g + 1, g + k + 1);
	g[k + 1] = s;
	ll left = 1, right = 2e9;
	while (left < right){
		ll mid = left + right >> 1;
		ll sum = 0;
		for (int i = 0; i <= k; ++ i){
			if (g[i + 1] - g[i] > mid){
				sum = INT_MAX;
				break;
			}
			if (g[i + 1] - g[i] << 1 <= mid){
				sum += g[i + 1] - g[i];
			}
			else{
				sum += (mid - (g[i + 1] - g[i])) + (2 * (g[i + 1] - g[i]) - mid) * 2;
			}
		}
		if (sum > t){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++ i){
		if (v[i] >= left){
			ans = std::min(ans, c[i]);
		}
	}
	printf("%d\n", ans == INT_MAX ? -1 : ans);
	return 0;
}