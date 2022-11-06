#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 1000010

int n, nn, m, q[2][maxn], f[maxn], fro[maxn], rec[maxn], sol[maxn], dr[maxn], qqq[maxn], qt[maxn];
struct trie
{
    int id, fr, tt;
    vector<int> nd, fnd;
    int f[10];
} t[maxn];
vector<int> v[maxn], w[maxn];

inline int cmp(int a, int b)
{
    if(t[t[a].tt].id!=t[t[b].tt].id)
        return t[t[a].tt].id<t[t[b].tt].id;

    return t[a].fr < t[b].fr;
}

void bf(int nod, int ttt)
{
    qqq[0]=1;
    qqq[1]=nod;
    qt[1]=ttt;

    for(int p=1; p<=qqq[0]; ++p)
    {
        f[nod]=1;
        nod=qqq[p];
        ttt=qt[p];

        t[nn].nd.push_back(nod);
        t[nn].fnd.push_back(ttt);

        for(int i=0; i<v[nod].size(); ++i)
        {
            if(f[v[nod][i]]==1 || w[nod][i]!=0)
                continue;

            qqq[++qqq[0]]=v[nod][i];
            f[v[nod][i]]=1;
            qt[qqq[0]]=nod;
        }
    }
}

int main()
{
    int a, b, c;
  //  freopen("g.in", "r", stdin);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        ++a;
        ++b;
        v[a].push_back(b);
        v[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }

    nn=1;
    t[nn].id=1;
    bf(n, 0);
    memset(f, 0, sizeof(f));

    q[0][0]=1;
    q[0][1]=1;

    int qq=0, nod, nt, nc;
    int id=1;
    while(f[1]==0)
    {
        q[1-qq][0]=0;

        for(int i=1; i<=q[qq][0]; ++i)
        {
            nt=q[qq][i];
            t[nt].id=++id;

            for(int j=0; j<t[nt].nd.size(); ++j)
            {
                nod = t[nt].nd[j];

          //      printf("%d\n", nod);

                if(f[nod])
                    continue;

                f[nod]=1;
                fro[nod]=t[nt].fnd[j];
                rec[nod]=t[nt].fr;

                for(int l=0; l<v[nod].size(); ++l)
                {
                    if(f[v[nod][l]])
                        continue;

                    if(t[nt].f[w[nod][l]]==0)
                    {
                        t[nt].f[w[nod][l]]=++nn;
                        q[1-qq][++q[1-qq][0]]=nn;

                        t[nn].fr=w[nod][l];
                        t[nn].tt=nt;
                    }

                    nc = t[nt].f[w[nod][l]];
                    t[nc].nd.push_back(v[nod][l]);
                    t[nc].fnd.push_back(nod);
                }
            }
        }

        sort(q[1-qq]+1, q[1-qq]+q[1-qq][0]+1, cmp);
        qq=1-qq;
    }

    int np=0;
    nod=1;

    while(nod!=n)
    {
        sol[++np]=nod;
        dr[np]=rec[nod];
        nod=fro[nod];
    }
    int ok=0;;

    for(int i=np; i>0; --i)
    {
        if(dr[i]!=0)
            ok=1;
        if(ok==1)
            printf("%d", dr[i]);
    }
    if(!ok)
        printf("0");

    printf("\n");

    printf("%d\n", np+1);
    for(int i=1; i<=np; ++i)
        printf("%d ", sol[i]-1);

    printf("%d\n", n-1);

    return 0;
}