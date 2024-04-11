#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(string s,int n)
{
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            ++ans;
        }
    }
    int mi=1e18;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            --ans;
        }
        else
        {
            ++ans;
        }
        mi=min(mi,ans);
    }
    return mi;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    cin>>s;
    int n=s.size();
    int ans=slv(s,n);
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            s[i]='0';
        }
        else
        {
            s[i]='1';
        }
    }
    ans=min(ans,slv(s,n));
    cout<<ans<<endl;
    }
    return 0;
}