#include <bits/stdc++.h>
using namespace std;
char a[30][30],b[30][30];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,w,t,i,j,k=0,pas=1<<15,m,sc,cnt=2,mx=1;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=m;++i)
        cin>>b[i];
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<a[(x-1)%n+1]<<b[(x-1)%m+1]<<'\n';
    }
    return 0;
}