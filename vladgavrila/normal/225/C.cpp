#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1010
#define inf 1000000000

int n, m, x, y, c1, c2;
int d[maxn][2], cost[maxn];
char s[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d%d%d\n", &n, &m, &x, &y);
    for(int i=1; i<=n; ++i)
    {
        scanf("%s", s);
        for(int j=0; j<m; ++j)
            if(s[j]=='#')
                ++cost[j+1];
    }


    for(int i=1; i<=m; ++i)
    {
        d[i][0]=d[i][1]=inf;
        c1=c2=0;
        for(int j=i; i-j+1<=y && j>0; --j)
        {
            c1=c1+cost[j];
            c2=c2+n-cost[j];
            if(i-j+1>=x)
            {
                d[i][1]=min(d[i][1], d[j-1][0]+c2);
                d[i][0]=min(d[i][0], d[j-1][1]+c1);
            }
        }
    }

    printf("%d\n", min(d[m][0], d[m][1]));

    return 0;
}