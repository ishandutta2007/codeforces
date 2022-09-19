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
        string s;
        cin>>s;
        int ca=0,cb=0,cc=0;
        for(auto h:s)
        {
            if(h=='A') ++ca;
            else if(h=='B') ++cb;
            else ++cc;
        }
        if(cb==(ca+cc)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}