#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 1100

int n, i, j, k, mdat, nr;
int a[maxn], b[maxn], sol[maxn];
pair<int, pair<int, int> > ev[maxn];
set<pair<int, int> > g;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        ev[i]=make_pair(a[i], make_pair(b[i], i));
    }
    sort(ev+1, ev+n+1);
    mdat=0;
    ev[n+1]=make_pair(2000000000, make_pair(0, 0));
    for(int i=1; i<=n; ++i)
    {
        g.insert(make_pair(ev[i].second.first, ev[i].second.second));
        mdat=max(mdat, ev[i].first);
        while(mdat<ev[i+1].first && g.size()>0)
        {
            nr=(*g.begin()).second;
            g.erase(g.begin());
            sol[nr]=mdat;
            mdat++;
        }
    }
    for(int i=1; i<=n; ++i)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
    return 0;
}