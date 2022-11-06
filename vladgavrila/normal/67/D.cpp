#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 1000010

int n, i, j, k, x, sol, sc;
int poz[maxn], v[maxn], ind[maxn], aib[maxn];

int lsb(int x)
{
    return (x&(x-1))^x;
}

void update(int x, int val)
{
    while(x<=n)
    {
        aib[x]=max(aib[x], val);
        x+=lsb(x);
    }
}

int query(int x)
{
    int rez=0;
    while(x)
    {
        rez=max(rez, aib[x]);
        x-=lsb(x);
    }
    return rez;
}

inline int cmp(int a, int b)
{
    return v[a]<v[b];
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        poz[x]=i;
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        v[i]=n-poz[x]+1;
        ind[i]=i;
    }

    sort(ind+1, ind+n+1, cmp);

    for(int i=1; i<=n; ++i)
    {
        sc=query(ind[i]-1);
        sol=max(sc+1, sol);
        update(ind[i], sc+1);
    }
    printf("%d\n", sol);
    return 0;
}