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
        int cnt0=0;int mi=1e18;int ma=(-1e18);
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='0') {cnt0++;mi=min(mi,i);ma=max(ma,i);}
        }
        if(cnt0==0)
        {
            cout<<0<<'\n';
        }
        else if(cnt0==(ma-mi+1))
        {
            cout<<1<<'\n';
        }
        else
        {
            cout<<2<<'\n';
        }
    }
    return 0;
}