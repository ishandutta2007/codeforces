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
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0')
            {
                ans+='0';
            }
            else
            {
                break;
            }
        }
        ans+='0';
        for(int i=(n-1);i>=0;i--)
        {
            if(s[i]=='1')
            {
                ans+='1';
            }
            else
            {
                break;
            }
        }
        if(ans.size()>n)
        {
            ans.erase(ans.begin());
        }
        cout<<ans<<endl;
    }
    return 0;
}