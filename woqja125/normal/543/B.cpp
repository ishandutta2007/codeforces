#include<stdio.h>
#include<vector>
int dist[3001][3001];
std::vector<int> map[3001];
int min(int a, int b){ return a>b?b:a; }
int main()
{
    int n, m, i, j, a, b;
    scanf("%d%d", &n, &m);
    for(i=1; i<=m; i++)
    {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for(i=1; i<=n; i++)
    {
        int que[3001], f=-1, r=-1;
        que[++r] = i;
        while(f<r)
        {
            int x = que[++f];
            for(auto xx: map[x]) if(xx!=i && dist[i][xx] == 0)
            {
                que[++r] = xx;
                dist[i][xx] = dist[i][x] + 1;
            }
        }
    }
    int s1, t1, l1, s2, t2, l2;
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    int ans = m+1;
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            int d1 = min(dist[s1][i] + dist[i][j] + dist[j][t1], dist[s1][j] + dist[i][j] + dist[i][t1]);
            int d2 = min(dist[s2][i] + dist[i][j] + dist[j][t2], dist[s2][j] + dist[i][j] + dist[i][t2]);
            if(d1 > l1) continue;
            if(d2 > l2) continue;
            if(ans > d1+d2-dist[i][j]) 
                ans = d1+d2-dist[i][j];
        }
    }
    if(dist[s1][t1] <= l1 && dist[s2][t2] <= l2) ans = min(ans, dist[s1][t1]+dist[s2][t2]);
    printf("%d", m-ans);
    return 0;
}