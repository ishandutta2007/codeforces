#include <bits/stdc++.h>
using namespace std;
int v[303][303];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mn=n+1;
        int ok=1;
        int a1;
        for(i=1;i<n;++i)
        {
            int a;
            cin>>a;
            if(i==1)
                a1=a;
            mn=min(mn,a);
            if(mn==n-i+1)
                ok=0;
        }
        int a;
        cin>>a;
        if(a1>a)
            ok=0;
        if(ok)
            cout<<"YEs\n";
        else
            cout<<"No\n";
    }
    return 0;
}