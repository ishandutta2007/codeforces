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
        string s;
        cin>>s;
        string ans;
        bool h=true;
        for(int i=0;i<s.size();++i)
        {
            if(!h)
            {
                ans+='0';
                continue;
            }
            if(s[i]=='2')
            {
                ans+='1';
            }
            if(s[i]=='1')
            {
                ans+='1';
                h=false;
            }
            if(s[i]=='0')
            {
                ans+='0';
            }
        }
        cout<<ans<<endl;
        string ans2;
        for(int i=0;i<n;++i)
        {
            ans2+=(s[i]-ans[i]+'0');
        }
        cout<<ans2<<endl;
    }
    return 0;
}