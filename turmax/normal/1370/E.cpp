#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int s1=0,s2=0;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;++i)
    {
        s1+=(s[i]-'0');
        s2+=(t[i]-'0');
        ans2=max(ans2,(s1-s2));
        ans1=min(ans1,s1-s2);
    }
    if(s1!=s2)
    {
        cout<<(-1);
        return 0;
    }
    cout<<ans2-ans1;
    return 0;
}