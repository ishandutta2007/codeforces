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
        cin>>a>>b>>c;
        int ans=1;
        for(int i=0;i<(c-1);++i) ans*=10;
        int x=ans;
        while(true)
        {
            x*=2;
            if(to_string(x).size()==a)
            {
                break;
            }
        }
        int y=ans;
        while(true)
        {
            y*=3;
            if(to_string(y).size()==b)
            {
                break;
            }
        }
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}