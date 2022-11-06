#include <cstdio>
#include <set>

using namespace std;

#define maxn 5500
#define maxd 110

int n, i, j, k, offset, nn, sol;
int v[maxn], nc[maxn], fol[maxn];
set<int> g;
long long fact[maxd], d[maxd][maxd];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &k);

    v[1]=4;
    v[2]=7;
    nc[1]=nc[2]=1;
    nn=2;
    for(int i=1; i<=nn; ++i)
    {
        if(nc[i]==9)
            continue;
        v[++nn]=v[i]*10+4;
        nc[nn]=nc[i]+1;
        v[++nn]=v[i]*10+7;
        nc[nn]=nc[i]+1;
    }

    for(int i=1; i<=nn; ++i)
    {
        if(v[i]<=n-13)
            ++sol;
        g.insert(v[i]);
    }

    if(n>13)
    {
        offset=n-13;
        n=13;
    }

    d[1][1]=1;
    fact[1]=1;

    for(int i=2; i<=n; ++i)
    {
        fact[i]=fact[i-1]*i;
        for(int j=1; j<=i; ++j)
            d[i][j]=1LL*j*fact[i-1];
    }

    if(k>d[n][n])
    {
        printf("-1\n");
        return 0;
    }

    for(int i=n; i; --i)
    {
        int poz=1;
        for(int j=1; j<=n; ++j)
        {
            if(fol[j]==1)
                continue;
            if(d[i][poz]>=k)
            {
                int nr=offset+j;
                int pz=offset+n-i+1;
                if(g.find(nr)!=g.end() && g.find(pz)!=g.end())
                    ++sol;
                fol[j]=1;
                k-=d[i][poz-1];
                break;
            }
            ++poz;
        }
    }

    printf("%d\n", sol);

    return 0;
}