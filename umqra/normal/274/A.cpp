#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define X first
#define Y second

const int N = (int)1e5 + 100;

bool used[N];
int dp[N][2];
vector <int> g[N];
ll a[N];

void dfs(int v)
{
    dp[v][0] = 0;
    dp[v][1] = 1;
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
        {
            dfs(to);
            dp[v][1] += dp[to][0];
            dp[v][0] += max(dp[to][1], dp[to][0]);
        }
    }
}

int myFind(ll x, int n)
{
    int l = -1, r = n;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] < x)
            l = m;
        else
            r = m;
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    ll k;
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {               
        int ind = myFind(a[i] * k, n);
        if (ind != -1)
        {
            g[ind].push_back(i);
            g[i].push_back(ind);
        }
    }   

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {        
            dfs(i);
            ans += max(dp[i][0], dp[i][1]);
        }
    }

    cout << ans;

    return 0;
}