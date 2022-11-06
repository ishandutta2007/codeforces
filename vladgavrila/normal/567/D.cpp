#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 300010

int n, k, m, a, ships, x;
long long sol;
set<pair<int, int> > g;

int getShips(int ll, int rr)
{
    return (rr-ll+2)/(a+1);
}

int main()
{
    scanf("%d%d%d", &n, &k, &a);

    g.insert(make_pair(n, 1));
    ships = getShips(1, n);

    scanf("%d", &m);

    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &x);
        set<pair<int, int> > :: iterator it = g.lower_bound(make_pair(x, 0));

        int ll=it->second;
        int rr=it->first;

        ships-=getShips(ll, rr);

        g.erase(it);

        if(ll!=x)
        {
            g.insert(make_pair(x-1, ll));
            ships+=getShips(ll, x-1);
        }
        if(rr!=x)
        {
            g.insert(make_pair(rr, x+1));
            ships+=getShips(x+1, rr);
        }

        if(ships<k)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}