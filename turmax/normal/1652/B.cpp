#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int ma[26];for(int i=0;i<26;++i) ma[i]=(-1);
        for(int i=0;i<s.size();++i) ma[s[i]-'a']=max(ma[s[i]-'a'],i);
        int ans=0;for(int i=0;i<26;++i) if(ma[i]!=(-1)) ans=max(ans,((int) s.size()-ma[i]));
        cout<<s.substr(s.size()-ans,ans)<<'\n';
    }
    return 0;
}