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
        int u=2;
        for(int k=1;k<40;++k)
        {
            u*=2;
            if(n%(u-1)==0)
            {
                cout<<(n/(u-1))<<endl;
                break;
            }
        }
    }
    return 0;
}