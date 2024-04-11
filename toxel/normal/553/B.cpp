#include<bits/stdc++.h>
#define ll long long

const int N = 100;

int n;
int ret[N];
ll k;
ll dp[N];

int main(){
	scanf("%d%I64d", &n, &k);
	-- k;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 1; i <= n; ++ i){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	std::vector <int> ans;
	for (int i = n; k; ){
		for (int j = i - 1; j >= 0; -- j){
			if (k >= dp[j]){
				k -= dp[j];
			}
			else{
				ans.push_back(i - j);
				i = j;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		ret[i] = i + 1;
	}
	int now = 0;
	for (auto u : ans){
		std::reverse(ret + now, ret + now + u);
		now += u;
	}
	for (int i = 0; i < n; ++ i){
		printf("%d ", ret[i]);
	}
	return 0;
}