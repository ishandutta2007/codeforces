#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 510
#define mod 1000000007

int n, m;
char s[maxn][maxn];
long long d[2][maxn][maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%s", s[i]+1);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(i+j-1!=(n+m-1)/2+(n+m-1)%2)
                continue;
            for(int k=1; k<=n; ++k)
            {
                int l=n+m+2-i-j-k;
                if(l<=0 || l>m)
                    continue;
                if((i==k || j==l) && s[i][j]==s[k][l])
                    d[0][j][k]=1;
            }
        }

    for(int i=(n+m-1)/2+(n+m-1)%2-1; i; --i)
    {
        for(int j=1; j<=m; ++j)
        {
            int a=i-j+1;
            int b=j;
            if(a<=0 || a>n)
                continue;
            for(int k=1; k<=n; ++k)
            {
                int l=n+m+2-a-b-k;
                if(l<=0 || l>m)
                    continue;

                if(s[a][b]==s[k][l])
                    d[1][b][k]= d[0][b+1][k]+
                                d[0][b][k]+
                                d[0][b+1][k-1]+
                                d[0][b][k-1];
                while(d[1][b][k]>=mod)
                    d[1][b][k]-=mod;
            }
        }

        memcpy(d[0], d[1], sizeof(d[0]));
        memset(d[1], 0, sizeof(d[1]));
    }

    printf("%d\n", (int)d[0][1][n]);

    return 0;
}