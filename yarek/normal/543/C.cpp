#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1 << 20];
char s[20][21];
int c[20][20];
int mn[20];
vector<pair<int, int> > g[26];
const int inf = 1000000000;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
	scanf("%s", s[i]);
    int N = 1 << n;
    for(int i = 1; i < N; i++)
	dp[i] = inf;
    for(int i = 0; i < n; i++)
    {
	mn[i] = inf;
	for(int j = 0; j < m; j++)
	{
	    scanf("%d", &c[i][j]);
	    mn[i] = min(mn[i], c[i][j]);
	}
    }
    for(int i = 0; i < m; i++)
    {
	for(int j = 0; j < n; j++)
	    g[s[j][i] - 'a'].push_back(make_pair(c[j][i], j));
	for(int j = 0; j < 26; j++)
	{
	    if(g[j].empty()) continue;
	    sort(g[j].begin(), g[j].end());
	    int sum = 0, mask = 1 << g[j].back().second;
	    for(int k = 0; k < g[j].size() - 1; k++)
	    {
		sum += g[j][k].first;
		mask |= 1 << g[j][k].second;
	    }
	    for(int k = 0; k < N; k++)
		dp[k | mask] = min(dp[k | mask], dp[k] + sum);
	    g[j].clear();
	}
    }
    int ans = inf;
    for(int i = 0; i < N; i++)
    {
	int sum = dp[i];
	for(int j = 0; j < n; j++)
	    if((i & (1 << j)) == 0)
		sum += mn[j];
	ans = min(ans, sum);
    }
    printf("%d\n", ans);
}