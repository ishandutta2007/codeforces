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
        string s1=s;
        sort(s1.begin(),s1.end());
        int ans=0;
        for(int i=0;i<n;++i) ans+=(s1[i]!=s[i]);
        cout<<ans<<'\n';
    }
    return 0;
}