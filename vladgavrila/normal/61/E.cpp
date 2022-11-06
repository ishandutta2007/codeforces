#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 1000010

int n, m;
int ind[maxn], aib[maxn], v[maxn], lg[maxn], sm[maxn];

int lsb(int x)
{
    return (x&(x-1))^x;
}

int query(int pz)
{
    int sol=0;
    while(pz)
    {
        sol+=aib[pz];
        pz-=lsb(pz);
    }
    return sol;
}

void update(int pz)
{
    while(pz<=n)
    {
        ++aib[pz];
        pz+=lsb(pz);
    }
}

inline int cmp(int a, int b)
{
    return v[a]<v[b];
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        ind[i]=i;
    }

    sort(ind+1, ind+n+1, cmp);

    for(int i=1; i<=n; ++i)
        v[ind[i]]=i;

    for(int i=1; i<=n; ++i)
    {
        sm[i]=i-1-query(v[i]);
        update(v[i]);
    }

    memset(aib, 0, sizeof(aib));

    reverse(v+1, v+n+1);

    for(int i=1; i<=n; ++i)
    {
        lg[n-i+1]=query(v[i]);
        update(v[i]);
    }

    long long sol=0;

    for(int i=1; i<=n; ++i)
        sol=sol+1LL*lg[i]*sm[i];

    printf("%I64d\n", sol);

    return 0;
}