#include <iostream>
using namespace std;
int mas[200][200];
int main()
{
    int n, m;
    cin >> n >> m;
    for ( int i=0; i<m; i++ )
    {
        int a, b;
        cin >> a >> b;
        mas[a][b]=1;
        mas[b][a]=1;
    }
    int k=-1;
    int rez=0;
    while ( k!=0 )
    {
          int v1[200], v2[200];
          k=0;
          for ( int i=1; i<=n; i++ )
          {
              int in=0, count=0;
              for ( int s=1; s<=n; s++ )
              {
                  if ( mas[i][s]==1 )
                  {
                     in=s;
                     count++;
                  }
              }
              if ( count==1 )
              {
                   k++;
                   v1[k-1]=i;
                   v2[k-1]=in;
              }
          }
          if ( k )
          {
             for ( int i=0; i<k; i++ )
             {
                 mas[v1[i]][v2[i]]=0;
                 mas[v2[i]][v1[i]]=0;
             }
             rez++;
          }
    }
    cout << rez;
    cin >> n;
    return 0;
}