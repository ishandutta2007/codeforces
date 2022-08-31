//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,m,k,x,y,rp[1000001],mins[1000001];
bool did[30001][101];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>did[i][j];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>x>>y;
        mins[x]++; rp[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=m;j++) if(did[i][j]) ans+=rp[j];
        ans-=mins[i];
        cout<<ans<<" ";
    }
    //***
    return 0;
}