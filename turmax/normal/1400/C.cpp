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
    int x;
    cin>>x;
    int n=s.size();
    string ans;
    for(int i=0;i<n;++i) ans+='1';
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            if((i-x)>=0)
            {
                ans[i-x]='0';
            }
            if((i+x)<n)
            {
                ans[i+x]='0';
            }
        }
    }
    bool h=true;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1' && (i<x || ans[i-x]=='0') && ((i+x)>=n || ans[i+x]=='0'))
        {
            h=false;
            cout<<(-1)<<endl;
            break;
        }
    }
    if(h)
    {
        cout<<ans<<endl;
    }
    }
    return 0;
}