#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 15001, LOG = 20, K = 1001;
const int p = 10000000 + 19, q = 1000000000 + 7;
int v[N];
int w[N];
int b[N];
int e[N];
int dp[N][K];
ll pw[K];
int n, k, d;


const int offset = 1 << 15;
vector<int> tree[offset << 1];
int ans[offset];


void insert(int k, int a, int b)
{
    a += offset; b += offset;
    while(a < b)
    {
        if(a & 1) tree[a++].push_back(k);
        if((b & 1) == 0) tree[b--].push_back(k);
        a >>= 1;
        b >>= 1;
    }
    if(a == b) tree[a].push_back(k);
}

void dfs(int nr, int a, int b)
{
//     printf("%d %d %d\n", nr, a, b);
    for(auto x: tree[nr])
    {
        copy(dp[d], dp[d] + k + 1, dp[d+1]);
        for(int i = k; i >= w[x]; i--)
            dp[d+1][i] = max(dp[d+1][i], dp[d][i-w[x]] + v[x]);
        d++;
    }
    if(a + 1 == b)
    {
        ll res = 0;
        for(int i = 1; i <= k; i++)
            res = (res + dp[d][i] * pw[i-1]) % q;
        ans[a] = res;
    }
    else
    {
        dfs(nr * 2, a, (a + b) / 2);
        dfs(nr * 2 + 1, (a + b) / 2, b);
    }
    d -= tree[nr].size();
}

int main()
{
    scanf("%d %d", &n, &k);
    pw[0] = 1;
    for(int i = 1; i <= k; i++)
        pw[i] = pw[i-1] * p % q;
    for(int i = 1; i <= n; i++)
        scanf("%d %d", v + i, w + i);
    int q;
    vector<int> th;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
    {
        int type;
        scanf("%d", &type);
        if(type == 3) th.push_back(i);
        else if(type == 2)
        {
            int x;
            scanf("%d", &x);
            e[x] = i;
        }
        else
        {
            n++;
            scanf("%d %d", v + n, w + n);
            b[n] = i;
        }
    }
    for(int i = 1; i <= n; i++)
        insert(i, b[i], e[i] ? e[i] : offset - 1);
    dfs(1, 0, offset);
    for(auto t: th)
        printf("%d\n", ans[t]);
}