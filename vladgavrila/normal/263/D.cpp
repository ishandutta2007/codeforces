#include <cstdio>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, k, a, b;
int st[maxn], f[maxn], niv[maxn];
int pz[maxn];
vector<int> v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int st0=1, nod, fiu;
    st[st0]=1;
    niv[1]=1;

    while(st0>0)
    {
        nod=st[st0];
        f[nod]=1;

        if(pz[nod]==v[nod].size())
        {
            --st0;
            continue;
        }

        while(f[v[nod][pz[nod]]]==1)
        {
            if(niv[v[nod][pz[nod]]]<=niv[nod]-k)
            {
                printf("%d\n", niv[nod]-niv[v[nod][pz[nod]]]+1);
                for(int i=niv[v[nod][pz[nod]]]; i<=niv[nod]; ++i)
                    printf("%d ", st[i]);
                printf("\n");
                return 0;
            }

            ++pz[nod];
            if(pz[nod]==v[nod].size())
                break;
        }

        if(pz[nod]==v[nod].size())
        {
            --st0;
            continue;
        }

        fiu=v[nod][pz[nod]];
        ++pz[nod];

        st[++st0]=fiu;
        f[fiu]=1;
        niv[fiu]=st0;
    }

    return 0;
}