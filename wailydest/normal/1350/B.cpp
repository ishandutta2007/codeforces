#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000;

int s[N];
int dp[N];

void testcase() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) dp[i] = 1;
	for (int i = 0; i < n; ++i) scanf("%d", s + i);
	for (int i = n; i > 0; --i) {
		for (int j = 2 * i; j <= n; j += i) if (s[i - 1] < s[j - 1]) dp[i - 1] = max(dp[i - 1], dp[j - 1] + 1);
	}
	printf("%d\n", *max_element(dp, dp + n));
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) testcase();
	return 0;
}