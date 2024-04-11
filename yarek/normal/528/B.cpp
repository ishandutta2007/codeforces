#include <cstdio>
#include <algorithm>
using namespace std;

int dp[600005];
int val[600000];

pair<int, int> v[200000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	scanf("%d %d", &v[i].first, &v[i].second);
	val[i*3] = v[i].first;
	val[i*3+1] = v[i].first - v[i].second;
	val[i*3+2] = v[i].first + v[i].second;
    }
    sort(val, val + 3 * n);
    sort(v, v + n);
    for(int i = 0, j = 0; i < n; i++)
    {
	int x = lower_bound(val, val + 3 * n, v[i].first) - val,
	    a = lower_bound(val, val + 3 * n, v[i].first - v[i].second) - val,
	    b = lower_bound(val, val + 3 * n, v[i].first + v[i].second) - val;
	while(j < x - 1)
	{
	    dp[j+1] = max(dp[j+1], dp[j]);
	    j++;
	}
	dp[b] = max(dp[b], dp[a] + 1);
    }
    printf("%d\n", *max_element(dp, dp + 3 * n + 1));
}