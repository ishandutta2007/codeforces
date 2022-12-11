#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1000003;
int k[M];
int p[M];
int dp[M];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	int a, b;
	scanf("%d %d", &a, &b);
	a++;
	k[a]++;
	p[a] = b;
    }
    for(int i = 1; i < M; i++)
    {
	if(k[i] == 0) dp[i] = dp[i-1];
	else dp[i] = dp[max(0, i - p[i] - 1)] + 1;
    }
    printf("%d\n", n - *max_element(dp, dp + M));
}