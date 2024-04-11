#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>c>>b;
        if(a<b)
        {
            cout<<1<<" ";
        }
        else
        {
            cout<<(-1)<<" ";
        }
        if(a*c>b)
        {
            cout<<c<<" ";
        }
        else
        {
            cout<<(-1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}