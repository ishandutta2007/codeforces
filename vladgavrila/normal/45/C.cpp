#include <stdio.h>
#include <set>

using namespace std;

#define maxn 200010

int n, i, j, k, sol, n1, n2, pv, sc;
int next[maxn], prev[maxn], v[maxn], f[maxn], a[maxn], b[maxn];
char s[maxn];
set<pair<int, pair<int, int> > >g;

int ab(int a)
{
    if(a<0) return -a;
    return a;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    scanf("%s", s+1);
    s[n+1]=s[n];

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        next[i]=i+1;
        prev[i]=i-1;
    }
    for(int i=1; i<=n; ++i)
        if(s[i]!=s[i+1])
            g.insert(make_pair(ab(v[i]-v[i+1]), make_pair(i, i+1)));
    while(g.size()>0)
    {
        n1=(*g.begin()).second.first;
        n2=(*g.begin()).second.second;
        g.erase(g.begin());
        if(f[n1]==1 || f[n2]==1 || next[n1]!=n2)
            continue;
        pv=prev[n1];
        sc=next[n2];
        f[n1]=f[n2]=1;
        a[++sol]=n1;
        b[sol]=n2;
        prev[sc]=pv;
        next[pv]=sc;
        if(s[pv]!=s[sc] && pv>0 && sc<=n)
            g.insert(make_pair(ab(v[pv]-v[sc]), make_pair(pv, sc)));
    }
    printf("%d\n", sol);
    for(int i=1; i<=sol; ++i)
    {
        printf("%d %d\n", a[i], b[i]);
    }
    return 0;
}