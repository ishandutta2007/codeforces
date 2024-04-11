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
        int n;
        cin>>n;
        bool h=false;
        for(int i=0;i<=(n/7);++i)
        {
            if(h)
            {
                break;
            }
            for(int j=0;j<=((n-7*i)/5);++j)
            {
                int x=n-i*7-5*j;
                if(x%3==0)
                {
                    cout<<x/3<<' '<<j<<' '<<i<<endl;
                    h=true;
                    break;
                }
            }
        }
        if(!h) cout<<(-1)<<endl;
    }
    return 0;
}