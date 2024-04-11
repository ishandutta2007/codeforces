#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int a,b,n;
        cin>>a>>b>>n;
        int x=0;
        for(int i=0;i<31;++i)
        {
            x+=(((a>>i)+(b>>i))%2)<<i;
        }
        if(n%3==0)
        {
            cout<<a<<endl;
        }
        else if(n%3==1)
        {
            cout<<b<<endl;
        }
        else if(n%3==2)
        {
            cout<<x<<endl;
        }
    }
    return 0;
}