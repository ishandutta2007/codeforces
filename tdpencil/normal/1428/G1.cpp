#include <bits/stdc++.h>
using namespace std;

static long long inf = (1LL << 58LL);
static long long F[6];
static long long ten[6] = {1, 10, 100, 1000, 10000, 100000};
static long long dp[1000005];
int N, K;

int main(){
	cin >> K;
	for(int i = 0;i <= 5;i++) cin >> F[i];
	
	int Q; cin >> Q;
	assert(Q == 1);
	
	int N; cin >> N;
	
	///0-1 knapsack with duplicate elements
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
	
	long long ans = 0;
	for(int X = 0;X <= N;X++){
		///calculating the fortune of X
		long long fortune = 0;
		int x = X;
		for(int d = 0;d <= 5;d++){
			int rem = x % 10;
			if(rem == 3 || rem == 6 || rem == 9) fortune += (rem / 3) * F[d];
			x /= 10;
		}
		
		ans = max(ans, fortune + dp[N-X]);
	}
	
	cout << ans;
}