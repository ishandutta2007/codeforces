#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

#define maxn 2010
#define inf 2000000000

int n, m, k;
string s1, s2;
int sk[maxn];
int d[maxn][maxn];

int main()
{
    cin>>s1;
    cin>>s2;

    n = s1.size();
    m = s2.size();

    for(int i=0; i<n; ++i)
    {
        int x=i;
        for(int j=0; j<m; ++j)
        {
            while(s1[x]!=s2[j] && x<n)
                ++x;
            if(x==n)
            {
                sk[i]=-1;
                break;
            }
            ++x;
        }
        if(sk[i]!=-1)
            sk[i]=x;
     //   printf("%d ", sk[i]);
    }
 //   printf("\n");

    for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
            d[i][j]=inf;

    d[0][0]=0;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            if(d[i][j]==inf)
                continue;
            d[i+1][j]=min(d[i+1][j], d[i][j]);
            if(sk[i]!=-1)
                d[sk[i]][j+1]=min(d[sk[i]][j+1], d[i][j]+(sk[i]-i-m));
        }

    int pz=0;

  //  for(int i=0; i<=n; ++i)
  //      printf("%d ", d[n][i]);
  //  printf("\n");

    for(int i=0; i<=n; ++i)
    {
        while(d[n][pz+1]<=i)
            ++pz;

        printf("%d ", min(pz, (n-i)/m));
    }
    printf("\n");

    return 0;
}