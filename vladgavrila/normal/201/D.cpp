#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

#define maxn 16
#define maxk 500100
#define inf 1000000000

int n, m, k, sol, nsol;
string v[maxn];
string c[maxk];
char conf[maxn];
int nxt[maxk][maxn];
int d[1<<maxn][maxn*maxn];

void solve(int pz)
{
    scanf("%d", &k);
    for(int i=1; i<=k; ++i)
    {
        cin>>c[i];
      //  cout<<c[i]<<"\n";

    }

    for(int i=1; i<=n; ++i)
        nxt[k+1][i]=k+1;

    for(int i=k; i>=0; --i)
    {
        for(int j=1; j<=n; ++j)
        {
            nxt[i][j]=nxt[i+1][j];
            if(c[i]==v[j])
                nxt[i][j]=i;
        }
    }

    for(int i=0; i<(1<<n); ++i)
        for(int j=0; j<=n*(n-1)/2; ++j)
            d[i][j]=inf;

    d[0][0]=0;

  //  for(int i=0; i<=k; ++i)
  //  {
   //     for(int j=1; j<=n; ++j)
    //        printf("%d ", nxt[i][j]);
   //     printf("\n");
  //  }

    int nc, x;
    for(int i=0; i<(1<<n)-1; ++i)
    {
        nc=0;
        for(int j=0; j<n; ++j)
        {
            conf[j]=(i>>j)&1;
        //    printf("%d", conf[j]);
            nc+=conf[j];
        }
     //   printf("\n");

     //   for(int l=0; l<=n*(n-1)/2; ++l)
     //       printf("%d ", d[i][l]);
    //    printf("\n");

        for(int j=0; j<n; ++j)
        {
            if(conf[j])
            {
                --nc;
                continue;
            }

            for(int l=0; l+nc<=n*(n-1)/2; ++l)
            {
                if(d[i][l]==inf)
                    continue;
                d[i|(1<<j)][l+nc]=min(d[i|(1<<j)][l+nc], nxt[d[i][l]][j+1]);
            }
        }
    }

    for(int i=0; i<=(n*(n-1)/2); ++i)
    {
        if(d[(1<<n)-1][i]<=k && (n*(n-1)/2)-i+1>sol)
        {
            sol=(n*(n-1)/2)-i+1;
            nsol=pz;
        }
    }

}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
        cin>>v[i];

    sol=0;

    scanf("%d\n", &m);
    for(int i=1; i<=m; ++i)
        solve(i);

    if(nsol==0)
    {
        printf("Brand new problem!\n");
        return 0;
    }

    printf("%d\n", nsol);
    printf("[:");
    for(int i=1; i<=sol; ++i)
        printf("|");
    printf(":]\n");

    return 0;
}