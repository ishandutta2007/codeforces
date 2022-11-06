#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 300010

int n, m, d[maxn], up[maxn];
pair<int, pair<int, int> > v[maxn];

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=m; ++i)
        scanf("%d%d%d", &v[i].second.first, &v[i].second.second, &v[i].first);

    sort(v+1, v+m+1);

    int j;
    for(int i=1; i<=m; i=j+1)
    {
        j=i;
        while(v[i].first==v[j+1].first)
            ++j;

        for(int k=i; k<=j; ++k)
            up[v[k].second.second]=max(up[v[k].second.second], d[v[k].second.first]+1);

        for(int k=i; k<=j; ++k)
            d[v[k].second.second]=max(d[v[k].second.second], up[v[k].second.second]);
    }

    int sol=0;
    for(int i=1; i<=n; ++i)
        sol=max(sol, d[i]);

    printf("%d\n", sol);

    return 0;
}