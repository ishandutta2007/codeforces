#include <stdio.h>
#include <string.h>

using namespace std;

#define maxn 410

int n, i, j, k, a, b, poz;
int d[maxn][maxn], t[maxn][maxn], bc[maxn];
char s[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d\n", &k, &a, &b);
    scanf("%s", s+1);
    n=strlen(s+1);
    d[0][0]=1;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<k; ++j)
        {
            if(d[i][j]==0)
                continue;
            for(int k=a; k<=b; ++k)
            {
                d[i+k][j+1]=1;
                t[i+k][j+1]=k;
            }
        }
    }
    if(d[n][k]==0)
    {
        printf("No solution\n");
        return 0;
    }
    poz=n;
    for(int i=k; i; i--)
    {
        bc[i]=t[poz][i];
        poz-=t[poz][i];
    }
    poz=1;
    for(int i=1; i<=n; ++i)
    {
        bc[i]+=bc[i-1];
        printf("%c", s[i]);
        if(bc[poz]==i)
        {
            printf("\n");
            ++poz;
        }
    }
    return 0;
}