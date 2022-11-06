#include<stdio.h>
#include<vector>
int n;
int e[100001][3];
int p[100001];
int l[100001];
int w[100001];
std::vector<int> map[100001], M[100001];
long long dp[100001], D[100001];
int C[100001];
void dfsF(int x, int par)
{
    int i, en, t;
    for(i=0; i<map[x].size(); i++)
    {
        en = map[x][i];
        t = e[en][0] + e[en][1] - x;
        if(t==par) continue;
        M[x].push_back(t);
        p[t] = x;
        l[en] = t;
        w[t] = e[en][2];
        dfsF(t, x);
    }
}
void dfsS(int x)
{
    int i;
    C[x] = 1;
    for(i=0; i<M[x].size(); i++)
    {
        dfsS(M[x][i]);
        C[x] += C[M[x][i]];
        D[x] += D[M[x][i]] + 1ll*C[M[x][i]]*w[M[x][i]];
        dp[x] += dp[M[x][i]];
    }
    for(i=0; i<M[x].size(); i++)
    {
        dp[x] += (D[M[x][i]] + 1ll*C[M[x][i]]*w[M[x][i]]) * (C[x]-C[M[x][i]]);
    }
}
int main()
{
    int i, q, a, b;
    long long tot;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
        map[e[i][0]].push_back(i);
        map[e[i][1]].push_back(i);
    }
    dfsF(1, -1);
    dfsS(1);
    tot = dp[1];
    scanf("%d", &q);
    for(i=1; i<=q; i++)
    {
        scanf("%d%d", &a, &b);
        a = l[a];
        b = w[a] - b;
        w[a] -= b;
        tot -= 1ll*C[a]*(n-C[a])*b;
        printf("%.10lf\n", (double)tot*6/n/(n-1));
    }
    return 0;
}