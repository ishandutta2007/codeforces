#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

const int maxn = 100005;
vector<pair<int, long long> > g[maxn];
char col[maxn];
long long dis[maxn];

void dfs(int s)
{
    col[s]=1;
    for(int i = 0; i<(int)g[s].size(); i++)
    {
        if (!col[g[s][i].first])
        {
            dis[g[s][i].first ]=dis[s]+g[s][i].second;
            dfs(g[s][i].first);
        }
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, i, a, b;
    long long sum, mx, c;
    scanf("%d", &n);
    sum = 0;
    for(i = 1; i < n; i++)
    {
        scanf("%d %d %I64d", &a, &b, &c);
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
        sum += c;
    }
    dfs(1);
    mx = 0;
    for(i = 1; i<= n; i++)
    {
        if (dis[i]>mx)
            mx = dis[i];
    }
    cout << 2ll * sum - mx;


}