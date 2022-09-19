#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<=1e8;i+=25)
    {
        string h=to_string(i);
        if(h.size()!=s.size()) continue;
        bool ok=true;
        int val=(-1);
        for(int j=0;j<s.size();++j)
        {
            if(h[j]!=s[j] && s[j]!='_' && s[j]!='X')
            {
                ok=false;
                break;
            }
            else if(s[j]=='X')
            {
                if(val==(-1))
                {
                    val=h[j]-'0';
                    continue;
                }
                else if(val!=(h[j]-'0'))
                {
                    ok=false;
                    break;
                }
            }
        }
        if(ok) ++ans;
    }
    cout<<ans;
    return 0;
}