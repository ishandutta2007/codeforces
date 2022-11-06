#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#define sigma 26
#define maxn 500010

int n, m, poz, lvmax;
vector<int> g[maxn], qq[maxn];
int v[maxn][sigma], q[maxn][sigma];
char s[maxn];
int qn[maxn], ql[maxn];

void df(int nod, int lvl)
{
    int x, fiu;

    for(int i=0; i<qq[nod].size(); ++i)
    {
        int qqn=qq[nod][i];
        for(int j=0; j<sigma; ++j)
            q[qqn][j]+=v[ql[qqn]][j];
    }

    ++v[lvl][s[nod-1]-'a'];

    for(int i=0; i<g[nod].size(); ++i)
        df(g[nod][i], lvl+1);

    for(int i=0; i<qq[nod].size(); ++i)
    {
        int qqn=qq[nod][i];
        for(int j=0; j<sigma; ++j)
            q[qqn][j]+=v[ql[qqn]][j];
    }
}

int main()
{
    int x;

    scanf("%d%d", &n, &m);

    for(int i=2; i<=n; ++i)
    {
        scanf("%d", &x);
        g[x].push_back(i);
    }

    scanf("%s", s);

    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &qn[i], &ql[i]);
        qq[qn[i]].push_back(i);
    }
    df(1, 1);

    for(int i=1; i<=m; ++i)
    {
        int imp=0;

        for(int j=0; j<sigma; ++j)
        {
           // printf("%d ", q[i][j]);
            imp+=q[i][j]%2;
        }
      //  printf("\n");

        if(imp<=1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}