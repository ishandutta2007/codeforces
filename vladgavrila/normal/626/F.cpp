#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 210
#define maxk 1010
#define mod 1000000007

int n, k;
int d[maxn][maxk][maxn];
int v[maxn];

int main()
{
    scanf("%d%d", &n, &k);

    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+n+1);
    d[1][0][0]=d[1][0][1]=1;

    for(int i=1; i<n; ++i)
    {
        for(int imb=0; imb<=k; ++imb)
        {
            for(int gr=0; gr<=n; ++gr)
            {
                if(d[i][imb][gr]==0)
                    continue;
                int nimb;
                //deschid grup nou
                nimb = imb + (v[i+1] - v[i])*gr;
                if(nimb <= k)
                {
                    d[i+1][nimb][gr+1] += d[i][imb][gr];
                    if(d[i+1][nimb][gr+1] >= mod)
                        d[i+1][nimb][gr+1] -= mod;
                }

                //pun un om nou pur singur
                nimb = imb + (v[i+1] - v[i])*gr;
                if(nimb <= k)
                {
                    d[i+1][nimb][gr] += d[i][imb][gr];
                    if(d[i+1][nimb][gr] >= mod)
                        d[i+1][nimb][gr] -= mod;
                }

                if(gr>0)
                {
                    //continui un grup vechi fara sa inchid
                    nimb = imb + (v[i+1] - v[i])*gr;
                    if(nimb <= k)
                    {
                        d[i+1][nimb][gr] += (1LL*gr*d[i][imb][gr])%mod;
                        if(d[i+1][nimb][gr] >= mod)
                            d[i+1][nimb][gr] -= mod;
                    }

                    //inchid un grup
                    nimb = imb + (v[i+1] - v[i])*gr;
                    if(nimb <= k)
                    {
                        d[i+1][nimb][gr-1] += (1LL*gr*d[i][imb][gr])%mod;
                        if(d[i+1][nimb][gr-1] >= mod)
                            d[i+1][nimb][gr-1] -= mod;
                    }
                }
            }
        }
    }

    int sol=0;
    for(int i=0; i<=k; ++i)
        sol=(sol+d[n][i][0])%mod;

    printf("%d\n", sol);

    return 0;
}