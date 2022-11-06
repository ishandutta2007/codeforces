#include <cstdio>

using namespace std;

#define maxn 500010

int n, m, x, q0;
int f[maxn], d[maxn], q[maxn], sol[maxn], na[maxn];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);

        q0=1;
        q[q0]=x;
        d[x]=0;
        f[x]=i;

        for(int j=1; j<=q0; ++j)
        {
            int nod=q[j];

            ++na[nod];
            sol[nod]+=d[nod];

            if(f[nod/2]!=i)
            {
                f[nod/2]=i;
                q[++q0]=nod/2;
                d[nod/2]=d[nod]+1;
            }

            if(nod*2>=maxn)
                continue;

            if(f[nod*2]!=i && nod*2<maxn)
            {
                f[nod*2]=i;
                q[++q0]=nod*2;
                d[nod*2]=d[nod]+1;
            }
        }
    }

    int ras = 1000000000;

    for(int i=0; i<maxn; ++i)
        if(na[i]==n && sol[i]<ras)
            ras=sol[i];

    printf("%d\n", ras);

    return 0;
}