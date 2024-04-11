#include <stdio.h>
#include <string.h>

using namespace std;

#define maxn 33

int n, m, q, tip, i, j, k, x, y, ok;
char v[maxn][maxn][maxn], f[maxn][maxn];
char s[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    while(q--)
    {
        scanf("%d", &tip);
        if(tip>0)
        {
            memset(s, 0, sizeof(s));
            scanf("%d %d %s", &x, &y, s);
            while(f[x][y]==1)
            {
                y++;
                if(y>m)
                {
                    y=1;
                    x++;
                }
                if(x==n+1)
                    break;
            }
            if(x==n+1)
                continue;
            f[x][y]=1;
            for(int i=0; i<10; ++i)
                v[x][y][i]=s[i];
        }
        if(tip==-1)
        {
            memset(s, 0, sizeof(s));
            scanf(" %s", s);
            ok=0;
            for(x=1; x<=n && !ok; ++x)
            {
                for(y=1; y<=m && !ok; ++y)
                {
                    if(f[x][y]==1)
                    {
                        ok=1;
                        for(int i=0; i<10; ++i)
                            if(v[x][y][i]!=s[i])
                                ok=0;
                    }
                    if(ok)
                        break;
                }
                if(ok) break;
            }
            if(!ok)
            {
                printf("-1 -1\n");
            }
            else
            {
                f[x][y]=0;
                for(int i=0; i<10; ++i)
                    v[x][y][i]=0;
                printf("%d %d\n", x, y);
            }
        }
    }
    return 0;
}