#include <cstdio>
#include <vector>

using namespace std;

#define maxn 200010

int n, m, k, x;
int sat[maxn], nst, sol[maxn], t[maxn], att[maxn];
int nap[maxn][4], nan[maxn][4];
vector<int> v[maxn];

int ab(int x)
{
    if(x>0)
        return x;
    return -x;
}

int tata(int nod)
{
    if(t[nod]==nod)
        return nod;

    int aux=tata(t[nod]);
    t[nod]=aux;
    return aux;
}

void process(int mc);

void mark(int e)
{
    if(sat[e]==1)
        return;

    ++nst;
    sat[e]=1;

    for(int i=0; i<v[e].size(); ++i)
        process(v[e][i]);
}

void process(int mc)
{
    if(att[mc]==1)
        return;
    if(nan[mc][0]==0)
    {
        att[mc]=1;
        sol[mc]=1;
        for(int i=1; i<=nap[mc][0]; ++i)
            mark(nap[mc][i]);
    }
    else
    if(nap[mc][0]==0)
    {
        att[mc]=1;
        sol[mc]=0;
        for(int i=1; i<=nan[mc][0]; ++i)
            mark(nan[mc][i]);
    }
    else
    if(sat[nan[mc][1]]==1)
    {
        att[mc]=1;
        sol[mc]=1;
        mark(nap[mc][1]);
    }
    else
    if(sat[nap[mc][1]]==1)
    {
        att[mc]=1;
        sol[mc]=0;
        mark(nan[mc][1]);
    }
    else
    {
        int t1=tata(nap[mc][1]);
        int t2=tata(nan[mc][1]);

        if(t1==t2)
        {
            att[mc]=1;
            sol[mc]=1;
            mark(nap[mc][1]);
        }
        else
        {
            t[t1]=t2;
            v[nan[mc][1]].push_back(mc);
            v[nap[mc][1]].push_back(mc);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i)
    {
        t[i]=i;
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d", &x);
            if(x<0)
                nan[-x][++nan[-x][0]]=i;
            else
                nap[x][++nap[x][0]]=i;
        }
    }

    for(int i=1; i<=m; ++i)
        process(i);

    if(nst==n)
    {
        printf("YES\n");
        for(int i=1; i<=m; ++i)
            printf("%d", sol[i]);
        printf("\n");
    }
    else
        printf("NO\n");

    return 0;
}