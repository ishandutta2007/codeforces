#include <stdio.h>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 10100

int n, i, j, poz, k, h, mh, dmg, reg, pow[maxn], st[maxn], ind[maxn];
priority_queue<pair<int,int> > g;
int sol[maxn], mom[maxn];

inline int cmp(int a, int b)
{
    return st[a]>st[b];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &mh, &reg);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &st[i], &pow[i]);
        ind[i]=i;
    }
    sort(ind+1, ind+n+1, cmp);
    h=mh;
    poz=1;
    while(poz<=n && st[ind[poz]]>=(h*100)/mh)
    {
        g.push(make_pair(pow[ind[poz]], -ind[poz]));
        ++poz;
    }
    i=0;
    for(i=0; h>0; ++i)
    {
        if(g.size()==0 && dmg<=reg)
        {
            printf("NO\n");
            return 0;
        }
        h-=dmg;
        h+=reg;
        h=min(h, mh);
        if(h<=0)
            break;
        while(poz<=n && st[ind[poz]]>=(1.0*h*100)/mh)
        {
            g.push(make_pair(pow[ind[poz]], -ind[poz]));
            ++poz;
        }
        if(g.size()>0)
        {
            sol[++sol[0]]=-(g.top()).second;
            mom[sol[0]]=i;
            dmg+=(g.top()).first;
            g.pop();
        }
    }
    printf("YES\n");
    printf("%d %d\n", i, sol[0]);
    for(int i=1; i<=sol[0]; ++i)
        printf("%d %d\n", mom[i], sol[i]);
    return 0;
}