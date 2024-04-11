#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 100010

int n, id[maxn], v[maxn];
long long k, spp[maxn];
pair<long long, int> sp[maxn];
int aib[maxn];

inline int lsb(int x)
{
    return (x&(x-1))^x;
}

int query(int poz)
{
    int sol=0;
    while(poz)
    {
        sol+=aib[poz];
        poz-=lsb(poz);
    }
    return sol;
}

void update(int poz)
{
    while(poz<=n+1)
    {
        ++aib[poz];
        poz+=lsb(poz);
    }
}

int solve(long long val)
{
    memset(aib, 0, sizeof(aib));

    long long nr=0;
    update(id[0]);

    int poz;
    for(int i=1; i<=n; ++i)
    {
        poz=int(upper_bound(sp, sp+n+1, make_pair(spp[i]-val, n+2))-sp);
        nr=nr+query(poz);
        update(id[i]);
    }

    if(nr>=k)
        return 1;
    return 0;
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%I64d", &n, &k);
    sp[0].second=0;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        spp[i]=spp[i-1]+v[i];
        sp[i].first=sp[i-1].first+v[i];
        sp[i].second=i;
    }

    sort(sp, sp+n+1);
    for(int i=0; i<=n; ++i)
        id[sp[i].second]=i+1;

    long long left=-(1LL*1000000000*200000), sol, right=(1LL*1000000000*200000), med;

    while(left<=right)
    {
        med=(left+right)/2;
        if(solve(med))
        {
            sol=med;
            left=med+1;
        }
        else
            right=med-1;
    }

    printf("%I64d\n", sol);

    return 0;
}