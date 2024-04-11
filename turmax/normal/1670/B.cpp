#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        int k;cin>>k;set<char> t;for(int i=0;i<k;++i) {char u;cin>>u;t.insert(u);}
        int cur=(-1);int ans=(-1);
        for(int i=0;i<n;++i)
        {
            if(!t.count(s[i])) ++cur;
            else {ans=max(ans,cur);cur=0;}
        }
        cout<<ans+1<<'\n';
    }
    return 0;
}