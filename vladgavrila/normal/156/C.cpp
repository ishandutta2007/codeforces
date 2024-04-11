#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 110
#define sigma 2610
#define mod 1000000007

int t, n, sum;
char v[maxn];
int d[maxn][sigma];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &t);

    d[0][0]=1;

    for(int i=1; i<=100; ++i)
    {
        for(int j=0; j<2600; ++j)
        {
            for(int x=0; x<26 && j-x>=0; ++x)
                d[i][j]=(d[i][j]+d[i-1][j-x])%mod;
        }
    }

    while(t--)
    {
        memset(v, 0, sizeof(v));

        scanf("%s", v+1);
        n=strlen(v+1);

        sum=0;
        for(int i=1; i<=n; ++i)
            sum+=v[i]-'a';

        printf("%d\n", (d[n][sum]+mod-1)%mod);
    }

    return 0;
}