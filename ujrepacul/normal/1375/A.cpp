#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a<0)
                a=-a;
            if(i%2==1)
                cout<<-a<<' ';
            else
                cout<<a<<' ';
        }
        cout<<'\n';
    }
    return 0;
}