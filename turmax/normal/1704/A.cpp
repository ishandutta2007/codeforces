#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;string s1,s2;cin>>s1>>s2;bool ok=true;for(int i=1;i<s2.size();++i) {ok=(ok && s1[i+n-m]==s2[i]);} bool ok1=false;for(int i=0;i<=n-m;++i) if(s1[i]==s2[0]) ok1=true; if(ok && ok1) cout<<"YES"<<'\n'; else cout<<"NO"<<'\n';
    }
    return 0;
}