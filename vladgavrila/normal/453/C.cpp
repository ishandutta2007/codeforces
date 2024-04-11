#include <cstdio>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, a, b, s0;
int p[maxn], t[maxn], q[maxn], f[maxn], sol[5*maxn];
vector<int> v[maxn];

void df(int nod)
{
    if(f[nod])
        return;

    f[nod]=1;
    q[nod]=1-q[nod];

    sol[++s0]=nod;

    for(int i=0; i<v[nod].size(); ++i)
    {
        if(f[v[nod][i]])
            continue;

        t[v[nod][i]]=nod;
        df(v[nod][i]);

        q[nod]=1-q[nod];
        sol[++s0]=nod;
    }

    if(q[nod]!=p[nod])
    {
        if(t[nod]==0)
        {
            --s0;
            q[nod]=1-q[nod];
        }
        else
        {
            sol[++s0]=t[nod];
            q[t[nod]]=1-q[t[nod]];

            sol[++s0]=nod;
            q[nod]=1-q[nod];
        }
    }
}


int main()
{
 //   freopen("c.in", "r", stdin);
//    freopen("c.out", "w", stdout);

    scanf("%d%d", &n, &m);
    while(m--)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; ++i)
        scanf("%d", &p[i]);

    for(int i=1; i<=n; ++i)
        if(p[i])
        {
            df(i);
            break;
        }

    for(int i=1; i<=n; ++i)
        if(p[i]!=q[i])
        {
            printf("-1\n");
            return 0;
        }

    printf("%d\n", s0);

    for(int i=1; i<=s0; ++i)
        printf("%d ", sol[i]);
    printf("\n");

    return 0;
}