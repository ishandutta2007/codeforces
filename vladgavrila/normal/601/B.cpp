#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 100010

int n, m;
int v[maxn], id[maxn];

int ab(int x)
{
    if(x<0)
        return -x;
    return x;
}

inline int cmp(int a, int b)
{
    return v[a]<v[b];
}

int t[maxn], f[maxn], mn[maxn], mx[maxn];

int tata(int nod)
{
    if(t[nod]==nod)
        return nod;
    int aux=tata(t[nod]);
    t[nod]=aux;
    return aux;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i<n; ++i)
        v[i]=ab(v[i]-v[i+1]);

    for(int i=1; i<n; ++i)
        id[i]=i;

    sort(id+1, id+n, cmp);

    while(m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        b--;
        memset(f, 0, sizeof(f));

        long long sol = 0;

        for(int i=1; i<n; ++i)
        {
            if(id[i]<a || id[i]>b)
                continue;

            int nod = id[i];
            f[nod]=1;
            t[nod]=nod;
            mx[nod]=mn[nod]=nod;

            int t1, t2;

            if(f[nod-1])
            {
                t1=tata(nod-1);
                t2=tata(nod);

                t[t1]=t2;
               // printf("%d %d %d\n", t1, mn[t1], mn[t2]);
                mn[t2]=min(mn[t1], mn[t2]);
                mx[t2]=max(mx[t1], mx[t2]);
            }
            if(f[nod+1])
            {
                t1=tata(nod+1);
                t2=tata(nod);

                t[t1]=t2;
                mn[t2]=min(mn[t1], mn[t2]);
                mx[t2]=max(mx[t1], mx[t2]);
            }

           // printf("%d %d\n", mx[nod], mn[nod]);


            sol = sol + (1LL*nod - mn[nod]+1) * (mx[nod]-nod+1) * v[id[i]];
        }
        printf("%I64d\n", sol);
    }

    return 0;
}