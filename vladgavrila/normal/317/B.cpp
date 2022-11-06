#include <cstdio>

using namespace std;

#define maxn 160

int n, m, t, x, y;
int v[maxn+1][maxn+1];
int newv[maxn+1][maxn+1];

int main()
{
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);

    scanf("%d", &n);
    v[maxn/2][maxn/2]=n;

    int ok=1;
    while(ok)
    {
        ok=0;
        for(int i=1; i<maxn; ++i)
            for(int j=1; j<maxn; ++j)
            {
                while(v[i][j]>=4)
                {
                    ++newv[i-1][j]; ++newv[i+1][j]; ++newv[i][j-1]; ++newv[i][j+1];
                    v[i][j]-=4;
                }
                newv[i][j]+=v[i][j];
            }

        for(int i=0; i<=maxn; ++i)
            for(int j=0; j<=maxn; ++j)
            {
                v[i][j]=newv[i][j];
                newv[i][j]=0;
                if(v[i][j]>=4)
                    ok=1;
            }
    }

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &x, &y);

        x+=maxn/2;
        y+=maxn/2;

        if(x<0 || x>maxn || y<0 || y>maxn)
            printf("0\n");
        else
            printf("%d\n", v[x][y]);
    }

    return 0;
}