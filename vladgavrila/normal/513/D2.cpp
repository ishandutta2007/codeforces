#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1000010
#define inf 1000000000

int n, m, nr, sol0, aa[maxn], bb[maxn], o[maxn];
int pz[maxn], lmn[maxn], lmx[maxn], rmn[maxn], rmx[maxn], sol[maxn];
char s[20];

int df(int right)
{
    int nod = ++nr;

    right=max(right, max(lmx[nod], rmx[nod]));

    if(rmn[nod]<=lmx[nod])
        return 0;

    int splitMin = max(nod, lmx[nod]);

    int ok=1;

    if(splitMin>nod)
        ok=min(ok, df(splitMin));

    if(nr>=rmn[nod])
        return 0;

    sol[++sol0]=nod;

    if(nr<right)
        ok=min(ok, df(right));

    return ok;
}

int main()
{
   // freopen("d.in", "r", stdin);
   // freopen("d.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        rmn[i]=lmn[i]=inf;
    int a, b;
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d %s", &a, &b, s);
        aa[i]=a;
        bb[i]=b;
        if(a>=b)
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        if(s[0]=='L')
        {
            lmn[a]=min(lmn[a], b);
            lmx[a]=max(lmx[a], b);
            o[i]=0;
        }
        else
        {
            rmn[a]=min(rmn[a], b);
            rmx[a]=max(rmx[a], b);
            o[i]=1;
        }
    }

    if(df(n))
    {
        for(int i=1; i<=n; ++i)
            pz[sol[i]]=i;

        for(int i=1; i<=m; ++i)
        {
            if((o[i]==1 && pz[aa[i]]>pz[bb[i]]) || (o[i]==0 && pz[aa[i]]<pz[bb[i]]))
            {
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }


        for(int i=1; i<=n; ++i)
            printf("%d ", sol[i]);
        printf("\n");
        return 0;
    }

    printf("IMPOSSIBLE\n");
    return 0;
}