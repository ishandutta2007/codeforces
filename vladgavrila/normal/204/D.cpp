#include <cstdio>

using namespace std;

#define maxn 1000010
#define mod 1000000007

int n, k;
int d[maxn][3][2];
int b[maxn], w[maxn];
char s[maxn];

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);

    scanf("%d%d\n", &n, &k);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i)
    {
        b[i]=b[i-1]; w[i]=w[i-1];
        if(s[i]=='W')
            ++w[i];
        if(s[i]=='B')
            ++b[i];
    }

    d[0][0][1]=1;
    for(int i=1; i<=n; ++i)
    {
        if(s[i]!='W')
        {
            //lvl 1
            d[i][0][0]=(d[i-1][0][0]+d[i-1][0][1])%mod;
            if(i>=k)
            {
                if(w[i]-w[i-k]==0)
                {
            //        d[i][0][0]=(d[i][0][0]+mod-d[i-k][0][0])%mod;
                    d[i][0][0]=(d[i][0][0]+mod-d[i-k][0][1])%mod;
                }
            }

            //lvl 2
            d[i][1][0]=(d[i-1][1][0]+d[i-1][1][1])%mod;
            if(i>=k)
            {
                if(w[i]-w[i-k]==0)
                    d[i][1][0]=(d[i][1][0]+d[i-k][0][1])%mod;
            }

            //lvl3
            d[i][2][0]=(d[i-1][2][0]+d[i-1][2][1])%mod;
        }
        if(s[i]!='B')
        {
            //lvl1
            d[i][0][1]=(d[i-1][0][0]+d[i-1][0][1])%mod;

            //lvl2
            d[i][1][1]=(d[i-1][1][0]+d[i-1][1][1])%mod;
            if(i>=k)
            {
                if(b[i]-b[i-k]==0)
                {
                    d[i][1][1]=(d[i][1][1]+mod-d[i-k][1][0])%mod;
                //    d[i][1][1]=(d[i][1][1]+mod-d[i-k][1][1])%mod;
                }
            }

            //lvl3
            d[i][2][1]=(d[i-1][2][0]+d[i-1][2][1])%mod;
            if(i>=k)
            {
                if(b[i]-b[i-k]==0)
                    d[i][2][1]=(d[i][2][1]+d[i-k][1][0])%mod;
            }
        }
    //    printf("%d %d\n", d[i][0][0], d[i][0][1]);
    //    printf("%d %d\n", d[i][1][0], d[i][1][1]);
    //    printf("%d %d\n\n", d[i][2][0], d[i][2][1]);

    }

    printf("%d\n", (d[n][2][0]+d[n][2][1])%mod);

    return 0;
}