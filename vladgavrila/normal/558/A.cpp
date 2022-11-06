#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m, p1, p2, sol;
pair<int, int> v[maxn];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d%d", &v[i].first, &v[i].second);

    sort(v+1, v+n+1);

    for(p2=1; p2<=n && v[p2].first<0; ++p2);

    p1=p2-1;

    while(p1>0 && p2<=n)
    {
        sol+=v[p2].second+v[p1].second;
        ++p2;
        --p1;
    }

    if(p2<=n)
        sol+=v[p2].second;
    if(p1>0)
        sol+=v[p1].second;

    printf("%d\n", sol);
    return 0;
}