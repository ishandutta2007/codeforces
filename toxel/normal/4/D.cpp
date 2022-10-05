#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
const int N = 5010;

std::pair <pii, int> p[N];
int dp[N], pre[N];

int main(){
	int n, w, h;
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 0, w, h; i < n; ++ i){
		scanf("%d%d", &w, &h);
		p[i] = {{w, h}, i + 1};
	}
	std::sort(p, p + n);
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < n; ++ i){
		if (p[i].first.first <= w || p[i].first.second <= h) continue;
		for (int j = 0; j < i; ++ j){
			if (p[j].first.first < p[i].first.first && p[j].first.second < p[i].first.second){
				if (dp[j] > dp[i]){
					dp[i] = dp[j];
					pre[i] = j;
				}
			}
		}
		++ dp[i];
	}
	int ssit = -1, max = 0;
	std::vector <int> ans;
	for (int i = 0; i < n; ++ i){
		if (dp[i] > max){
			max = dp[i];
			ssit = i;
		}
	}
	printf("%d\n", max);
	while (~ssit){
		ans.push_back(p[ssit].second);
		ssit = pre[ssit];
	}
	std::reverse(ans.begin(), ans.end());
	for (int i = 0, sz = ans.size(); i < sz; ++ i){
		printf("%d%c", ans[i], " \n"[i == sz - 1]);
	}
	return 0;
}