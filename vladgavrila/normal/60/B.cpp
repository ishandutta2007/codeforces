#include <stdio.h>

using namespace std;

#define maxn 12
#define maxc 10010

int n, m, i, j, k, sz, s1, s2;
int f[maxn][maxn][maxn], o[maxn][maxn][maxn];
int ca[maxc], cb[maxc], cc[maxc];
char s[maxn];
const int d1[]={0, 0, 0, 0, -1, 1};
const int d2[]={0, 0, -1, 1, 0, 0};
const int d3[]={-1, 1, 0, 0, 0, 0};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &k, &n, &m);
    for(int x=1; x<=k; ++x)
    {
        for(int y=1; y<=n; ++y)
        {
            scanf("%s", s+1);
            for(int z=1; z<=m; ++z)
            {
                if(s[z]=='.')
                    o[x][y][z]=0;
                else
                    o[x][y][z]=1;
            }
        }
    }

    scanf("%d%d", &s1, &s2);
    if(o[1][s1][s2]==1)
    {
        printf("0\n");
        return 0;
    }
    sz=1;
    ca[1]=1, cb[1]=s1; cc[1]=s2;
    f[1][s1][s2]=1;
    for(int i=1; i<=sz; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            int nx=ca[i]+d1[j];
            int ny=cb[i]+d2[j];
            int nz=cc[i]+d3[j];
            if(nx>0 && nx<=k && ny>0 && ny<=n && nz>0 && nz<=m && o[nx][ny][nz]==0 && f[nx][ny][nz]==0)
            {
                ca[++sz]=nx;
                cb[sz]=ny;
                cc[sz]=nz;
                f[nx][ny][nz]=1;
            }
        }
    }
    printf("%d\n", sz);
    return 0;
}