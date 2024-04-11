#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 2010

int n, m, k, q;
vector<int> x[maxn], y[maxn];
vector<long long> v[maxn];
int lg[maxn];
int on[maxn];
int who[maxn][maxn], pp[maxn][maxn];
char cop[10];
vector<int> inter[maxn];

void insertElem(int poz, int xx, int yy, int vv)
{
    v[poz].push_back(vv);
    x[poz].push_back(xx);
    y[poz].push_back(yy);

    who[xx][yy]=poz;
    pp[xx][yy]=v[poz].size()-1;
}

int inSquare(int xx, int yy, int x1, int y1, int x2, int y2)
{
    return (x1<=xx) && (xx<=x2) && (y1<=yy) && (yy<=y2);
}

void solveQuery()
{
    int x1, x2, y1, y2;
    scanf("%d%d%d%d\n", &x1, &y1, &x2, &y2);
   // printf("%d %d %d %d\n", x1, y1, x2, y2);

    //laturi orizontale
    for(int j=y1; j<=y2; ++j)
    {
        int cg=who[x1][j];
        if(on[cg]!=0)
        {
            int cp = pp[x1][j];
            if(!inSquare(x[cg][cp-1], y[cg][cp-1], x1, y1, x2, y2))
                inter[cg].push_back(pp[x1][j]);
            if(!inSquare(x[cg][cp+1], y[cg][cp+1], x1, y1, x2, y2))
                inter[cg].push_back(pp[x1][j]);
        }

        if(x1!=x2)
        {
            cg=who[x2][j];
            if(on[cg]!=0)
            {
                int cp = pp[x2][j];
                if(!inSquare(x[cg][cp-1], y[cg][cp-1], x1, y1, x2, y2))
                    inter[cg].push_back(pp[x2][j]);
                if(!inSquare(x[cg][cp+1], y[cg][cp+1], x1, y1, x2, y2))
                    inter[cg].push_back(pp[x2][j]);
            }
        }
    }

    //laturi verticale
    for(int i=x1+1; i<=x2-1; ++i)
    {
        int cg=who[i][y1];
        if(on[cg]!=0)
        {
            int cp = pp[i][y1];
            if(!inSquare(x[cg][cp-1], y[cg][cp-1], x1, y1, x2, y2))
                inter[cg].push_back(pp[i][y1]);
            if(!inSquare(x[cg][cp+1], y[cg][cp+1], x1, y1, x2, y2))
                inter[cg].push_back(pp[i][y1]);
        }

        if(y1!=y2)
        {
            cg=who[i][y2];
            if(on[cg]!=0)
            {
                int cp = pp[i][y2];
                if(!inSquare(x[cg][cp-1], y[cg][cp-1], x1, y1, x2, y2))
                    inter[cg].push_back(pp[i][y2]);
                if(!inSquare(x[cg][cp+1], y[cg][cp+1], x1, y1, x2, y2))
                    inter[cg].push_back(pp[i][y2]);
            }
        }
    }

    //capete
    for(int i=1; i<=k; ++i)
    {
        if(on[i]==0)
            continue;

//printf("!%d %d\n", x[i][1], y[i][1]);

        if(inSquare(x[i][1], y[i][1], x1+1, y1+1, x2-1, y2-1))
            inter[i].push_back(1);
        if(inSquare(x[i][lg[i]], y[i][lg[i]], x1+1, y1+1, x2-1, y2-1))
            inter[i].push_back(lg[i]);
    }
    //calcul

    long long csol = 0;
    for(int i=1; i<=k; ++i)
    {
        if(on[i])
        {
            sort(inter[i].begin(), inter[i].end());

        //    printf("%d\n", inter[i].size());
        //    printf("%d: ", i);
        //    for(int j=0; j<inter[i].size(); j++)
        //        printf("%d ", inter[i][j]);
       //     printf("\n");

            for(int j=0; j<inter[i].size(); j+=2)
                csol += v[i][inter[i][j+1]] - v[i][inter[i][j]-1];
        }
        inter[i].clear();
    }

    printf("%I64d\n", csol);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=k; ++i)
    {
        scanf("%d", &lg[i]);
        insertElem(i, 0, 0, 0);

        for(int j=1; j<=lg[i]; ++j)
        {
            int xx, yy, vv;
            scanf("%d%d%d", &xx, &yy, &vv);
            insertElem(i, xx, yy, vv);
            v[i][j]+=v[i][j-1];
        }

        insertElem(i, 0, 0, 0);
    }

    scanf("%d\n", &q);


    for(int i=1; i<=k; ++i)
        on[i]=1;

    while(q--)
    {
        scanf("%s", cop);
        if(cop[0]=='A')
            solveQuery();
        else
        {
            int w;
            scanf("%d\n", &w);
            on[w]=1-on[w];
        }
    }

    return 0;
}