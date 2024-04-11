#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define maxn 110

int n, m, nr;
long long v[maxn], aux[maxn];
pair<long long, int> p[maxn];
int l[maxn], x[maxn][3];

long long dist(int x[], int y[])
{
    return 1LL*(y[0]-x[0])*(y[0]-x[0])+1LL*(y[1]-x[1])*(y[1]-x[1])+1LL*(y[2]-x[2])*(y[2]-x[2]);
}

void addDist(int pz)
{
    long long dis;
    for(int i=1; i<pz; ++i)
    {
        dis=dist(x[i], x[pz]);
        for(int j=1; j<=nr+1; ++j)
        {
            if(j==nr+1)
            {
                aux[j]=dis;
                l[j]=1;
                ++nr;
                break;
            }
            if(aux[j]==dis)
            {
                ++l[j];
                break;
            }
        }
    }
}

void remDist(int pz)
{
    long long dis;
    for(int i=1; i<pz; ++i)
    {
        dis=dist(x[i], x[pz]);
        for(int j=1; j<=nr; ++j)
        {
            if(aux[j]==dis)
            {
                --l[j];
                if(l[j]==0)
                {
                    swap(l[j], l[nr]);
                    swap(aux[j], aux[nr]);
                    --nr;
                }
                break;
            }
        }
    }
}

void back(int pz)
{
    if(pz==9)
    {
        if(nr<3)
            return;
        for(int i=1; i<=3; ++i)
            p[i]=make_pair(aux[i], l[i]);
        sort(p+1, p+3+1);

        if(p[2].first!=p[1].first*2 || p[3].first!=p[1].first*3)
            return;

        if(p[1].second!=12 || p[2].second!=12 || p[3].second!=4)
            return;

        for(int i=2; i<=8; ++i)
            for(int j=2; j<=8; ++j)
                if(dist(x[1], x[i])==p[1].first && dist(x[1], x[j])==p[1].first &&
                   1LL*(x[j][0]-x[1][0])*(x[i][0]-x[1][0])+1LL*(x[j][1]-x[1][1])*(x[i][1]-x[1][1])+1LL*(x[j][2]-x[1][2])*(x[i][2]-x[1][2])==0)
                {
                    printf("YES\n");
                    for(int i=1; i<=8; ++i)
                    {
                        for(int j=0; j<3; ++j)
                            printf("%d ", x[i][j]);
                        printf("\n");
                    }
                    exit(0);
                }
        return;
    }

    addDist(pz);
    if(nr<=3)
        back(pz+1);
    remDist(pz);

    swap(x[pz][2], x[pz][1]);

    addDist(pz);
    if(nr<=3)
        back(pz+1);
    remDist(pz);

    swap(x[pz][2], x[pz][0]);

    addDist(pz);
    if(nr<=3)
        back(pz+1);
    remDist(pz);

    swap(x[pz][2], x[pz][1]);

    addDist(pz);
    if(nr<=3)
        back(pz+1);
    remDist(pz);

    swap(x[pz][2], x[pz][0]);

    addDist(pz);
    if(nr<=3)
        back(pz+1);
    remDist(pz);

    swap(x[pz][2], x[pz][1]);

    addDist(pz);
    if(nr<=3)
        back(pz+1);
    remDist(pz);

    swap(x[pz][2], x[pz][0]);
}

int main()
{
    for(int i=1; i<=8; ++i)
        for(int j=0; j<3; ++j)
            scanf("%d", &x[i][j]);

    back(1);

    printf("NO\n");

    return 0;
}