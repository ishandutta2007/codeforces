#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 300010

int n, m, p, sol;
long long b, w;
multiset<long long> g;
pair<long long, long long> v[maxn];

void umfla()
{
    while(v[p].first>b && p>0)
    {
        g.insert(v[p].second-v[p].first+1);
        --p;
    }
}
int main()
{
    scanf("%d", &n);
    --n;
    scanf("%lld%lld", &b, &w);
    for(int i=1; i<=n; ++i)
        scanf("%lld%lld", &v[i].first, &v[i].second);

    sort(v+1, v+n+1);

    p=n;
    umfla();
    sol=g.size();

    while(b>=0)
    {
        if(g.size()==0)
        {
            sol=0;
            break;
        }
        if(b>=*g.begin())
        {
            b-=*g.begin();
            g.erase(g.begin());
            umfla();
            sol=min(sol, int(g.size()));
        }
        else
            break;
    }

    printf("%d\n", sol+1);

    return 0;
}