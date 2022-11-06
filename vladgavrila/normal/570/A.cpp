#include <cstdio>

using namespace std;

#define maxn 110

int n, m;
int v[maxn][maxn];
int w[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m+1; ++i)
    {
        w[i]=1;
        for(int j=1; j<=n; ++j)
        {
            if(i!=m+1)
                scanf("%d", &v[i][j]);
            if(v[i][w[i]]<v[i][j])
                w[i]=j;
        }
        if(i!=m+1)
            ++v[m+1][w[i]];
    }

    printf("%d\n", w[m+1]);

    return 0;
}