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
        if(n>=4e6)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool h=false;
        for(int i=0;i<((n+2020)/2020);++i)
        {
            int j=(n-i*2020);
            if(j%2021==0 && j>=0)
            {
                cout<<"YES"<<endl;
                h=true;
                break;
            }
        }
        if(!h) cout<<"NO"<<endl;
    }
    return 0;
}