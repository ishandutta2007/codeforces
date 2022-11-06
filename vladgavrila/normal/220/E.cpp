#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define maxn 100010

int n, m, pz;
int v[maxn], o[maxn];
long long a1[maxn], a2[maxn];
long long k, nis, nid, nim, sol;
map<int, int> mp;

int lsb(int x)
{
    return (x&(x-1))^x;
}

void update(long long aib[], int poz, int val)
{
    while(poz<=n)
    {
        aib[poz]+=val;
        poz+=lsb(poz);
    }
}

long long query(long long aib[], int poz)
{
    long long rez=0;
    while(poz)
    {
        rez+=aib[poz];
        poz-=lsb(poz);
    }
    return rez;
}

void move_pz()
{
    nid-=query(a2, v[pz]-1);
    nim-=(query(a1, n)-query(a1, v[pz]));
    update(a2, v[pz], -1);

    ++pz;
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%I64d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        o[i]=v[i];
    }

    sort(o+1, o+n+1);
    for(int i=1; i<=n; ++i)
        if(mp[o[i]]==0)
            mp[o[i]]=i;

    for(int i=1; i<=n; ++i)
        v[i]=mp[v[i]];

    for(int i=1; i<=n; ++i)
    {
        update(a2, v[i], 1);
        nid+=query(a2, n)-query(a2, v[i]);
    }

    pz=1;

    for(int i=1; i<n; ++i)
    {
        if(pz==i)
            move_pz();
        if(pz==n+1)
            break;

        update(a1, v[i], 1);
        nis+=query(a1, n)-query(a1, v[i]);

        nim+=query(a2, v[i]-1);


        while(nis+nim+nid>k)
        {
            if(pz==n+1)
                break;
            move_pz();
            if(pz==n+1)
                break;
        }
        if(pz==n+1)
            break;

        sol+=n-pz+1;
    }

    printf("%I64d\n", sol);

    return 0;
}