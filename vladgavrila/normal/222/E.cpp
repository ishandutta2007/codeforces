#include <cstdio>
#include <cstring>

using namespace std;

#define mod 1000000007
#define maxn 55

long long n;
int m, k;
int v[maxn][maxn], p[maxn][maxn], aux[maxn][maxn];
char c1, c2;
int sol;

void inm(long long exp)
{
    if(exp==1)
    {
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=m; ++j)
                v[i][j]=p[i][j];
        return;
    }

    inm(exp/2);

    memset(aux, 0, sizeof(aux));

    for(int l=1; l<=m; ++l)
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=m; ++j)
                aux[i][j]=(aux[i][j]+1LL*v[i][l]*v[l][j])%mod;

    for(int i=1; i<=m; ++i)
        for(int j=1; j<=m; ++j)
            v[i][j]=aux[i][j];

    if(exp%2)
    {
        memset(aux, 0, sizeof(aux));

        for(int l=1; l<=m; ++l)
            for(int i=1; i<=m; ++i)
                for(int j=1; j<=m; ++j)
                    aux[i][j]=(aux[i][j]+1LL*v[i][l]*p[l][j])%mod;

        for(int i=1; i<=m; ++i)
            for(int j=1; j<=m; ++j)
                v[i][j]=aux[i][j];
    }
}


int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%I64d%d%d\n", &n, &m, &k);
    if(n==1)
    {
        printf("%d\n", m);
        return 0;
    }
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=m; ++j)
            p[i][j]=1;

    for(int i=1; i<=k; ++i)
    {
        scanf("%c%c\n", &c1, &c2);
        if(c1>='a')
            c1=c1-'a';
        else
            c1=c1-'A'+26;

        if(c2>='a')
            c2=c2-'a';
        else
            c2=c2-'A'+26;
        p[c1+1][c2+1]=0;
    }

    inm(n-1);

    for(int i=1; i<=m; ++i)
        for(int j=1; j<=m; ++j)
            sol=(sol+v[i][j])%mod;

    printf("%d\n", sol);

    return 0;
}