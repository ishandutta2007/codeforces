#include <cstdio>
#include <set>

using namespace std;

#define maxn 100010

int n, k, m, sol, msf, a[maxn];
long long b;
set<pair<int, int> > g;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &k);
    scanf("%I64d", &b);

    msf=sol=n;
    for(int i=1; i<n; ++i)
    {
        scanf("%d", &a[i]);
        g.insert(make_pair(-a[i], i));
    }

    for(int i=1; i<=k; ++i)
    {
        if(g.empty())
            break;

        while(-(g.begin()->first)>b)
        {
            sol=min(sol, min(msf, g.begin()->second));
            g.erase(g.begin());

            if(g.empty())
                break;
        }

        if(g.empty())
            break;

        msf=min(msf, g.begin()->second);
        b+=(g.begin()->first);
        g.erase(g.begin());

        if(b<0)
            sol=min(sol, msf);
    }

    printf("%d\n", sol);

    return 0;
}