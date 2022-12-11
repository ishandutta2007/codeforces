#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a[101][101];int ceil[101]={0};int core[101]={0};
    int i,n,m,k,j,l;
    cin>>n>>m>>k;
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++) cin>>a[i][j];
    for(j=1;j<=m;j++)
    {
          for(i=1;i<=k;i++) if (ceil[i]>=0) ceil[i]=0;
          for(i=1;i<=n;i++) if ((core[i]==0)&&(a[i][j]))
           {
               if (ceil[a[i][j]]==0) ceil[a[i][j]]=i;else
               if (ceil[a[i][j]]>0) {core[i]=j; core[ceil[a[i][j]]]=j;ceil[a[i][j]]=-1;}else
               if (ceil[a[i][j]]==-1) core[i]=j;

           }
    }
    for(i=1;i<=n;i++) cout<<core[i]<<endl;
}