#include <stdio.h>

using namespace std;

#define maxn 110

int n, m, i, j, k, ok, sol;
int armin, sx, sy;
char s[maxn][maxn];

int cmp(int x1, int y1, int x2, int y2, int x, int y)
{
    int ok=1;
    for(int i1=x1, i2=x2; i1<x1+x && ok; ++i1, ++i2)
        for(int j1=y1, j2=y2; j1<y1+y && ok; ++j1, ++j2)
            if(s[i1][j1]!=s[i2][j2])
            {
                ok=0;
                break;
            }
    if(ok)
        return 1;
    ok=1;
    for(int i1=x1, i2=x2+x-1; i1<x1+x && ok; ++i1, --i2)
        for(int j1=y1, j2=y2+y-1; j1<y1+y && ok; ++j1, --j2)
            if(s[i1][j1]!=s[i2][j2])
            {
                ok=0;
                break;
            }
    if(ok)
        return 1;
    if(x==y)
    {
        ok=1;
        for(int i1=x1, i2=y2+x-1; i1<x1+x && ok; ++i1, --i2)
            for(int j1=y1, j2=x2; j1<y1+y && ok; ++j1, ++j2)
                if(s[i1][j1]!=s[j2][i2])
                {
                    ok=0;
                    break;
                }
        if(ok)
            return 1;
        for(int i1=x1, i2=y2; i1<x1+x && ok; ++i1, ++i2)
            for(int j1=y1, j2=x2+x-1; j1<y1+y && ok; ++j1, --j2)
                if(s[i1][j1]!=s[j2][i2])
                {
                    ok=0;
                    break;
                }
        if(ok)
            return 1;
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    armin=1000000000;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%s", s[i]+1);
    for(int x=1; x<=n; ++x)
    {
        for(int y=1; y<=m; ++y)
        {
            if(n%x!=0 || m%y!=0)
                continue;
            ok=1;
            for(int p1x=1; p1x<=n && ok; p1x+=x)
                for(int p1y=1; p1y<=m && ok; p1y+=y)
                    for(int p2x=1; p2x<=n && ok; p2x+=x)
                        for(int p2y=1; p2y<=m && ok; p2y+=y)
                        {
                            if(p1x==p2x && p1y==p2y)
                                continue;
                            if(cmp(p1x, p1y, p2x, p2y, x, y)==1)
                            {
                                ok=0;
                                break;
                            }
                        }
            if(ok)
            {
                ++sol;
                if(x*y<armin)
                {
                    armin=x*y;
                    sx=x;
                    sy=y;
                }
            }
        }
    }
    printf("%d\n%d %d\n", sol, sx, sy);
    return 0;
}