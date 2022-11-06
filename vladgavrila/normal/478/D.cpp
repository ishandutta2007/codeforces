#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 400010
#define mod 1000000007

int n, m, r, g;
int d[2][maxn], f[2][maxn], sf[maxn];

int sum(int a, int b)
{
    if(a>b)
        return 0;
    if(a==0)
        return sf[b];
    return sf[b]-sf[a-1];
}

int main()
{
    scanf("%d%d", &r, &g);

    d[0][0]=1;
    f[0][0]=1;

    int sol = 0, nmc = 0, tot;

    for(int i = 1; i <= 900; ++i)
    {
        tot = (i*(i+1)/2);
        for(int j = 0; j <= r && j <= tot; ++j)
        {
            d[1][j] = d[0][j];
            f[1][j] = f[0][j];

            if(j>=i)
            {
                if(f[0][j-i]==1)
                {
                    f[1][j]=1;
                    d[1][j]+=d[0][j-i];
                    if(d[1][j]>=mod)
                        d[1][j]-=mod;
                }
            }

            if(j)
                sf[j]=f[1][j]+sf[j-1];
        }

        if(sum(max(0, tot-g), min(r, tot))==0)
        {
            tot = (i-1)*i/2;
            break;
        }

        for(int j = 0; j <= r && j <= tot; ++j)
        {
            d[0][j] = d[1][j];
            f[0][j] = f[1][j];
        }
    }

    for(int i = max(0, tot-g); i <= min(r, tot); ++i)
    {
        sol = sol + d[0][i];
        if(sol >= mod)
            sol -= mod;
    }
    printf("%d\n", sol);

    return 0;
}