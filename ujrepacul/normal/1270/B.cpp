#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    int n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=2;i<=n;++i)
        {
            if(max(v[i]-v[i-1],v[i-1]-v[i])>=2)
            {
                cout<<"YES\n";
                cout<<i-1<<' '<<i<<'\n';
                break;
            }
        }
        if(i==n+1)
        {
            cout<<"NO\n";
        }
    }
    return 0;
}