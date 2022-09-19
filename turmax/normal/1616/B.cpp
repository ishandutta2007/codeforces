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
        int n;cin>>n;
        string s;cin>>s;
        s.push_back('z'+1);++n;
        int l=0;while(s[l+1]==s[l]) ++l;
        if(l>=1)
        {
            cout<<s[0]<<s[0]<<'\n';
            continue;
        }
        for(int i=0;i<n;++i) if(s[i]<s[i+1])
        {
            string h=s.substr(0,i+1);
            string t=h;reverse(h.begin(),h.end());t+=h;
            cout<<t<<'\n';
            break;
        }
    }
    return 0;
}