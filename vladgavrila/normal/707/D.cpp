#include <cstdio>
#include <bitset>

using namespace std;

#define maxn 1010
#define maxq 100010

int n, m, q;
bitset<maxn> v[maxq];
int p[maxq];
int sol[maxq], sz[maxq];
int a[maxq], b[maxq], c[maxq];

int numara(int pz)
{
    sz[pz]=0;

    for(int i=1; i<=m; ++i)
        sz[pz]+=int(v[pz][i]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for(int i=1; i<=q; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        if(a[i]<=2)
            scanf("%d", &c[i]);
    }

    for(int crs=1; crs<=n; ++crs)
    {
        int nr = 0;

        for(int i=1; i<=q; ++i)
        {
            if(a[i]==1 || a[i]==2)
            {
                if(b[i]!=crs)
                    p[i]=p[i-1];
                else
                {
                    v[++nr]=v[p[i-1]];
                    p[i]=nr;

                    if(a[i]==1)
                        v[nr].set(c[i], 1);
                    else
                        v[nr].set(c[i], 0);

                    numara(nr);
                }
            }
            if(a[i]==3)
            {
                if(b[i]!=crs)
                    p[i]=p[i-1];
                else
                {
                    v[++nr]=v[p[i-1]];
                    p[i]=nr;

                    for(int j=1; j<=m; ++j)
                        v[nr].flip(j);

                    numara(nr);
                }
            }
            if(a[i]==4)
                p[i]=p[b[i]];

            sol[i]+=sz[p[i]];
        }
    }

    for(int i=1; i<=q; ++i)
        printf("%d\n", sol[i]);

    return 0;
}