#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 4010
#define nseconds 86400

int n, k, sol;
int d[maxn][maxn];
int s[maxn], t[maxn];

int getTime(int pz)
{
    if(pz>n)
        return nseconds+1;
    return s[pz];
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d%d", &s[i], &t[i]);

    sol=getTime(k+1) - 1;

    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<=i && j<=k; ++j)
        {
            d[i][j]=max(d[i-1][j]+t[i], s[i]+t[i]-1);
            if(j>0)
                d[i][j]=min(d[i][j], d[i-1][j-1]);
            sol=max(sol, getTime(i+k-j+1) - d[i][j] - 1);
        }
    }

    printf("%d\n", sol);
    return 0;
}