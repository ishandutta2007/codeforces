#include <iostream>
using namespace std;

int main() 
{
	int n, k;
	cin >> n >> k;
	
	string str;
	cin >> str;
	
	long long dp[200001];
	dp[n] = 0;
	for (int i = 0; i < n; ++i) dp[i] = LLONG_MAX;
	
	int prev[200000];
	
	int cur = -200001;
	for (int i = n - 1; i >= -k; --i) {
		if (i >= 0 && str[i] == '1') cur = i;
		if (i + k < n) prev[i + k] = cur;
	}
	
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = min(dp[i], dp[i + 1] + i + 1);
		if (prev[i] + k >= i) dp[max(0, prev[i] - k)] = min(dp[max(0, prev[i] - k)], dp[i + 1] + prev[i] + 1);
	}
	
	cout << dp[0] << '\n';
	
	return 0;
}