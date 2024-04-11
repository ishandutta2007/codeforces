#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 310

int n, m, vmax, nod, q0, cr, sol, pzq[maxn];
long long  sa, sb;
int a[maxn], b[maxn];
int f[maxn][maxn], fol[maxn], q[maxn];
int xa[maxn*maxn], xb[maxn*maxn], xc[maxn*maxn];

void df(int nod)
{
    fol[nod]=1;
    sa+=a[nod];
    sb+=b[nod];

    for(int i=1; i<=n; ++i)
        if(f[nod][i]==1 && fol[i]==0)
            df(i);

    q[++q0]=nod;
    pzq[nod]=q0;
}

int cere(int nod, int cant)
{

    fol[nod]=1;
    int cc, x;
    if(pzq[nod]==cr)
        cc=0;
    else
    {
        cc=min(a[nod], cant);
        a[nod]-=cc;
    }

    for(int i=1; i<=n && cc<cant; ++i)
    {
        if(fol[i]==0 && f[i][nod]==1 && pzq[i]>cr)
        {
            x=cere(i, cant-cc);
            if(x>0)
            {
                xa[++sol]=i;
                xb[sol]=nod;
                xc[sol]=x;
            }
            cc+=x;
        }
    }

    if(pzq[nod]==cr)
    {
        a[nod]+=cc;
    }

    return cc;
}

int da(int nod, int cant)
{
    fol[nod]=1;

    int cc, x;
    if(pzq[nod]==cr)
        cc=0;
    else
    {
    //    printf("!");
        cc=min(vmax-a[nod], cant);
        a[nod]+=cc;
    }

    for(int i=1; i<=n && cc<cant; ++i)
    {
   //     printf("%d %d\n", pzq[i], cr);
        if(fol[i]==0 && f[i][nod]==1 && pzq[i]>cr)
        {
            x=da(i, cant-cc);
            if(x>0)
            {
                xa[++sol]=nod;
                xb[sol]=i;
                xc[sol]=x;
            }
            cc+=x;
        }
    }

    if(pzq[nod]==cr)
    {
        a[nod]-=cc;
    }


    return cc;
}


int main()
{
   // freopen("c.in", "r", stdin);
   // freopen("c.out", "w", stdout);

    scanf("%d%d%d", &n, &vmax, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i)
        scanf("%d", &b[i]);

    while(m--)
    {
        scanf("%d%d", &sa, &sb);
        f[sa][sb]=f[sb][sa]=1;
    }

    for(int i=1; i<=n; ++i)
        if(fol[i]==0)
        {
            sa=sb=0;
            df(i);
            if(sa!=sb)
            {
                printf("NO\n");
                return 0;
            }
        }

    for(int i=1; i<=n; ++i)
    {
        nod=q[i];
        cr=i;
        memset(fol, 0, sizeof(fol));
        if(a[nod]<b[nod])
            cere(nod, b[nod]-a[nod]);
        if(b[nod]<a[nod])
            da(nod, a[nod]-b[nod]);
    }

    printf("%d\n", sol);
    for(int i=1; i<=sol; ++i)
        printf("%d %d %d\n", xa[i], xb[i], xc[i]);

    printf("\n");

    return 0;
}