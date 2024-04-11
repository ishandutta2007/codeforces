#include <bits/stdc++.h>
using namespace std;

const long long inf = (1LL << 58LL);
long long F[6];
long long fortune[10] = {0, 0, 0, 1, 0, 0, 2, 0, 0, 3};
long long ten[6] = {1, 10, 100, 1000, 10000, 100000};
long long dp[1000005];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int K; int N = 999999;
	
	cin >> K;
	for(int i = 0;i <= 5;i++) cin >> F[i];
	
	
	fill(dp,dp+N+1,-inf); dp[0] = 0;
	for(int d = 0;d <= 5;d++){
		long long left = 3 * (K - 1);
		long long group = 1;
		
		///grouping 3*(K-1) elements into groups of powers of 2
		while(left > 0){
			group = min(group, left);
			
			long long value = group * F[d];
			long long weight = group * ten[d] * 3;
			for(int i = N;i >= weight;i--) dp[i] = max(dp[i], dp[i-weight] + value); ///knapsack DP
			
			left -= group;
			group *= 2;
		}
	}
	
	for(int d = 0;d <= 5;d++){
		for(int i = N;i >= 0;i--){
			for(int b = 1;b <= 9;b++){
				int pre = i - ten[d] * b;
				if(pre < 0) break;
				dp[i] = max(dp[i], dp[pre] + fortune[b] * F[d]);
			}
		}
	}
	
	int Q; cin >> Q;
	while(Q--){
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
}