#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        long long a,b,x,y;
        cin>>a>>b>>x>>y;
        a=max(a-x,x-a);
        b=max(b-y,y-b);
        if(a==0 || b==0)
        {
            cout<<a+b<<'\n';
        }
        else
        {
            cout<<a+b+2<<'\n';
        }
    }
    return 0;
}