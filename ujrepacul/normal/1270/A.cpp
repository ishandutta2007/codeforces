#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>n>>a>>b;
        for(i=1;i<=a;++i)
        {
            int x;
            cin>>x;
            if(x==n)
                k=1;
        }
        for(i=1;i<=b;++i)
        {
            int x;
            cin>>x;
            if(x==n)
                k=2;
        }
        if(k==1)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}