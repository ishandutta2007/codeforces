#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 1040

int n, m, k, p1, p2, mx, pt, sol;
int a[maxn], b[maxn], r[maxn], cx[maxn], cy[maxn];
vector<int> ls[maxn];

long long dist(int ax, int ay, int bx, int by)
{
    return 1LL*(ay-by)*(ay-by)+1LL*(ax-bx)*(ax-bx);
}

inline int cmp(int a, int b)
{
    return r[a]>r[b];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    for(int i=1; i<=m; ++i)
        scanf("%d%d%d", &r[i], &cx[i], &cy[i]);
    r[0]=2000000000;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(dist(cx[j], cy[j], a[i], b[i])<1LL*r[j]*r[j])
                ls[i].push_back(j);
        }
        ls[i].push_back(0);
        sort(ls[i].begin(), ls[i].end(), cmp);
    }
    for(int i=1; i<=k; ++i)
    {
        scanf("%d%d", &p1, &p2);
        mx=min(ls[p1].size(), ls[p2].size());
        for(pt=1; pt*2<mx; pt*=2);
        sol=0;
        for(; pt; pt/=2)
        {
            if(sol+pt>=mx)
                continue;
            if(ls[p1][sol+pt]==ls[p2][sol+pt])
                sol+=pt;
        }
        printf("%d\n", ls[p1].size()+ls[p2].size()-2*sol-2);
    }
    return 0;
}