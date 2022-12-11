#include <bits/stdc++.h>
using namespace std;

const int N = 35001, K = 51;
int dp[K][N];
int a[N];
int cnt[N];

int be = 1, en, diff;

void move(int nb, int ne)
{
    while(be > nb)
    {
        be--;
        if(cnt[a[be]]++ == 0)
            diff++;
    }
    while(en < ne)
    {
        en++;
        if(cnt[a[en]]++ == 0)
            diff++;
    }
    while(be < nb)
    {
        if(--cnt[a[be]] == 0)
            diff--;
        be++;
    }
    while(en > ne)
    {
        if(--cnt[a[en]] == 0)
            diff--;
        en--;
    }
}

struct req
{
    int a, b, oa, ob;
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i++)
    {
        move(1, i);
        dp[1][i] = diff;
    }
    for(int i = 2; i <= k; i++)
    {
        queue<req> q;
        q.push({1, n, 1, n});
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            if(x.a > x.b) continue;
            int c = (x.a + x.b) / 2;
            move(x.oa, c);
            dp[i][c] = dp[i-1][x.oa-1] + diff;
            int opt = x.oa;
            for(int j = x.oa + 1; j <= x.ob && j <= c; j++)
            {
                move(j, c);
                int k = diff + dp[i-1][j-1];
                if(dp[i][c] <= k)
                {
                    dp[i][c] = k;
                    opt = j;
                }
            }
            q.push({x.a, c-1, x.oa, opt});
            q.push({c+1, x.b, opt, x.ob});
        }
    }
    printf("%d\n", dp[k][n]);
}