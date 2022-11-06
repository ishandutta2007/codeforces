#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 500010

int n, i, j, k, nr, sol, x[maxn], y[maxn], h[maxn], a[maxn], b[maxn];
struct eveniment
{
    int poz, tip, who;
} ev[maxn];
set<pair<int, int> > g;

inline int cmp(eveniment a, eveniment b)
{
    return a.poz<b.poz;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d%d", &h[i], &x[i], &y[i]);
        ev[++nr].poz=x[i];
        ev[nr].tip=1;
        ev[nr].who=i;
        ev[++nr].poz=y[i];
        ev[nr].tip=-1;
        ev[nr].who=i;
    }
    sort(ev+1, ev+nr+1, cmp);
    ev[0].poz=-2000000000;
    ev[nr+1].poz=2000000000;
    g.insert(make_pair(0, -1));
    for(int i=1; i<=nr; ++i)
    {
        a[++sol]=ev[i].poz;
        b[sol]=-(*g.begin()).first;
        while(ev[i].poz==ev[i+1].poz)
        {
            if(ev[i].tip==1)
                g.insert(make_pair(-h[ev[i].who], ev[i].who));
            else
                g.erase(make_pair(-h[ev[i].who], ev[i].who));
            ++i;
        }
        if(ev[i].tip==1)
            g.insert(make_pair(-h[ev[i].who], ev[i].who));
        else
            g.erase(make_pair(-h[ev[i].who], ev[i].who));
        a[++sol]=ev[i].poz;
        b[sol]=-(*g.begin()).first;
        if(b[sol]==b[sol-1])
        {
            sol-=2;
        }
    }
    printf("%d\n", sol);
    for(int i=1; i<=sol; ++i)
    {
        printf("%d %d\n", a[i], b[i]);
    }
    return 0;
}