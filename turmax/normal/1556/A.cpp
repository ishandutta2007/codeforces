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
        int x,y;
        cin>>x>>y;
        if(x==0 && y==0)
        {
            cout<<0<<'\n';
            continue;
        }
        if((x+y)%2==0 && (x+y)>=0)
        {
             if(abs(x)==abs(y))
             {
                 cout<<1<<'\n';
                 continue;
             }
             else
             {
                 cout<<2<<'\n';
                 continue;
             }
        }
        else
        {
            cout<<(-1)<<'\n';
            continue;
        }
    }
    return 0;
}