#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define maxn 1000010

int n, m, nr, x;
map<int, int> mp;
int a[maxn], v[maxn];
int f1[maxn], f2[maxn], cnt[maxn];

inline int lsb(int x)
{
    return (x&(x-1))^x;
}

void update(int pz)
{
    while(pz<maxn)
    {
        ++a[pz];
        pz+=lsb(pz);
    }
}

int query(int pz)
{
    int sol=0;
    while(pz>0)
    {
        sol+=a[pz];
        pz-=lsb(pz);
    }
    return sol;
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        if(mp[x]==0)
            mp[x]=++nr;
        v[i]=mp[x];
        ++cnt[v[i]];
        f1[i]=cnt[v[i]];
    }

    memset(cnt, 0, sizeof(cnt));

    long long sol=0;

    for(int i=n; i>0; --i)
    {
        ++cnt[v[i]];
        f2[i]=cnt[v[i]];

        sol=sol+query(f1[i]-1);
        update(f2[i]);
    }

    printf("%I64d\n", sol);

    return 0;
}